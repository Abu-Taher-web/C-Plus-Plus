#include "RGBA/png.h"
#include "RGBA/rgbapixel.h"

#include <string>
#include <cmath>

#include "intro.h"
#include <mpfr.h>
#include <filesystem> // For directory creation

void rotate(const std::string & inputFile, const std::string & outputFile) {
	PNG pic(inputFile);
	// Your code here
	int input_img_width = pic.width();
	int input_img_height = pic.height();

	int output_img_width = input_img_height;
	int output_img_height = input_img_width;
	PNG rotatedPic(output_img_width, output_img_height);
	
	for(unsigned int x = 0; x<pic.width(); x++ ){
		for(unsigned int y = 0; y<pic.height(); y++){
			rotatedPic(y, pic.width()-1-x) = pic(x, y);
		}
	}
	
	rotatedPic.writeToFile(outputFile);
}
/*
PNG myArt(unsigned int width, unsigned int height) {
	PNG png(width, height);
	// Your code here
	 // Center of the image
	unsigned int centerX = width / 2;
	unsigned int centerY = height / 2;

	for(unsigned int x = 0; x < width; x++){
		for(unsigned int y = 0; y<height; y++){
			RGBAPixel &pixel = png(x, y);
			// Calculate distance from the center
            double distance = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
            double maxDistance = sqrt(centerX * centerX + centerY * centerY);

            // Set color based on distance
            pixel.red = static_cast<uint8_t>((255 * distance) / maxDistance);
            pixel.green = 0;
            pixel.blue = static_cast<uint8_t>(255 - (255 * distance) / maxDistance);
            pixel.alpha = 255;
        }
		}

		return png;
	}
*/

//Mandelbrot fractal
/*
PNG myArt(unsigned int width, unsigned int height) {

    PNG png(width, height);

    // Mandelbrot parameters
    const int maxIterations = 100;
    const double zoom = 200.0;
    const double offsetX = width / 2.0;
    const double offsetY = height / 2.0;

    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            // Scale pixel position to Mandelbrot coordinates
            double zx = 0.0, zy = 0.0;
            double cx = (x - offsetX) / zoom;
            double cy = (y - offsetY) / zoom;

            int iteration = 0;
            while (zx * zx + zy * zy < 4.0 && iteration < maxIterations) {
                double temp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = temp;
                iteration++;
            }

            // Set color based on iterations
            RGBAPixel &pixel = png(x, y);
            pixel.red = static_cast<uint8_t>((iteration * 10) % 255);
            pixel.green = static_cast<uint8_t>((iteration * 20) % 255);
            pixel.blue = static_cast<uint8_t>((iteration * 30) % 255);
            pixel.alpha = 255;
        }
    }

    return png;
}

*/

//Julia Set
/*
PNG myArt(unsigned int width, unsigned int height) {
    PNG png(width, height);

    // Julia set parameters
    const int maxIterations = 100;
    const double zoom = 200.0;
    const double offsetX = width / 2.0;
    const double offsetY = height / 2.0;
    const double cX = -0.7, cY = 0.27015; // Constants for Julia set

    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            // Scale pixel position to Julia set coordinates
            double zx = (x - offsetX) / zoom;
            double zy = (y - offsetY) / zoom;

            int iteration = 0;
            while (zx * zx + zy * zy < 4.0 && iteration < maxIterations) {
                double temp = zx * zx - zy * zy + cX;
                zy = 2.0 * zx * zy + cY;
                zx = temp;
                iteration++;
            }

            // Set color based on iterations
            RGBAPixel &pixel = png(x, y);
            pixel.red = static_cast<uint8_t>((iteration * 10) % 255);
            pixel.green = static_cast<uint8_t>((iteration * 20) % 255);
            pixel.blue = static_cast<uint8_t>((iteration * 30) % 255);
            pixel.alpha = 255;
        }
    }

    return png;
}
*/


//combination of mandalbort and gradient
/*
PNG myArt(unsigned int width, unsigned int height) {
    PNG png(width, height);

    // Gradient background
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            RGBAPixel &pixel = png(x, y);
            pixel.red = static_cast<uint8_t>((255 * x) / width);
            pixel.green = static_cast<uint8_t>((255 * y) / height);
            pixel.blue = 0;
            pixel.alpha = 255;
        }
    }

    // Fractal overlay (Mandelbrot set)
    const int maxIterations = 100;
    const double zoom = 200.0;
    const double offsetX = width / 2.0;
    const double offsetY = height / 2.0;

    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            double zx = 0.0, zy = 0.0;
            double cx = (x - offsetX) / zoom;
            double cy = (y - offsetY) / zoom;

            int iteration = 0;
            while (zx * zx + zy * zy < 4.0 && iteration < maxIterations) {
                double temp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = temp;
                iteration++;
            }

            if (iteration < maxIterations) {
                RGBAPixel &pixel = png(x, y);
                pixel.red = static_cast<uint8_t>((iteration * 10) % 255);
                pixel.green = static_cast<uint8_t>((iteration * 20) % 255);
                pixel.blue = static_cast<uint8_t>((iteration * 30) % 255);
            }
        }
    }

    return png;
}
*/

PNG myArt(unsigned int width, unsigned int height, double zoom, double zoomCenterX, double zoomCenterY, int maxIterations) {
    PNG png(width, height);

    // MPFR variables for high-precision calculations
    mpfr_t zx, zy, cx, cy, temp, zx_squared, zy_squared, zx_squared_plus_zy_squared;
    mpfr_init2(zx, 256); // 256-bit precision
    mpfr_init2(zy, 256);
    mpfr_init2(cx, 256);
    mpfr_init2(cy, 256);
    mpfr_init2(temp, 256);
    mpfr_init2(zx_squared, 256);
    mpfr_init2(zy_squared, 256);
    mpfr_init2(zx_squared_plus_zy_squared, 256);

    double offsetX = width / 2.0;
    double offsetY = height / 2.0;

    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            // Scale pixel position to Mandelbrot coordinates
            mpfr_set_d(cx, zoomCenterX + (x - offsetX) / zoom, MPFR_RNDN);
            mpfr_set_d(cy, zoomCenterY + (y - offsetY) / zoom, MPFR_RNDN);
            mpfr_set_d(zx, 0.0, MPFR_RNDN);
            mpfr_set_d(zy, 0.0, MPFR_RNDN);

            int iteration = 0;
            while (iteration < maxIterations) {
                // Calculate zx^2 and zy^2
                mpfr_mul(zx_squared, zx, zx, MPFR_RNDN);
                mpfr_mul(zy_squared, zy, zy, MPFR_RNDN);

                // Calculate zx^2 + zy^2
                mpfr_add(zx_squared_plus_zy_squared, zx_squared, zy_squared, MPFR_RNDN);

                // Check if zx^2 + zy^2 >= 4.0
                if (mpfr_cmp_d(zx_squared_plus_zy_squared, 4.0) >= 0) {
                    break;
                }

                // Calculate new zx and zy
                mpfr_sub(temp, zx_squared, zy_squared, MPFR_RNDN); // temp = zx^2 - zy^2
                mpfr_add(temp, temp, cx, MPFR_RNDN);               // temp = temp + cx
                mpfr_mul(zy, zx, zy, MPFR_RNDN);                  // zy = 2 * zx * zy
                mpfr_mul_d(zy, zy, 2.0, MPFR_RNDN);               // zy = zy * 2
                mpfr_add(zy, zy, cy, MPFR_RNDN);                  // zy = zy + cy
                mpfr_set(zx, temp, MPFR_RNDN);                    // zx = temp

                iteration++;
            }

            // Set color based on iterations
            RGBAPixel &pixel = png(x, y);
            pixel.red = static_cast<uint8_t>((iteration * 10) % 255);
            pixel.green = static_cast<uint8_t>((iteration * 20) % 255);
            pixel.blue = static_cast<uint8_t>((iteration * 30) % 255);
            pixel.alpha = 255;
        }
    }

    // Clear MPFR variables
    mpfr_clear(zx);
    mpfr_clear(zy);
    mpfr_clear(cx);
    mpfr_clear(cy);
    mpfr_clear(temp);
    mpfr_clear(zx_squared);
    mpfr_clear(zy_squared);
    mpfr_clear(zx_squared_plus_zy_squared);

    return png;
}


void generateZoomAnimation(unsigned int width, unsigned int height, const std::string &outputDir) {
    double zoom = 200.0;
    double zoomFactor = 1.1; // Smaller zoom factor for smoother zooming
    int frames = 100;         // Number of frames in the animation
    int maxIterations = 500;  // Increase iterations for higher zoom levels

    // Focus on the Mandelbrot bulb
    double zoomCenterX = 0.28; // X-coordinate of the zoom center
    double zoomCenterY = 0.53;   // Y-coordinate of the zoom center

    // Create the output directory if it doesn't exist
    if (!std::filesystem::exists(outputDir)) {
        std::filesystem::create_directory(outputDir);
    }

    for (int frame = 0; frame < frames; frame++) {
        std::cout << "Frame " << frame << ": zoom = " << zoom << ", maxIterations = " << maxIterations << std::endl;

        PNG png = myArt(width, height, zoom, zoomCenterX, zoomCenterY, maxIterations);
        std::string filename = outputDir + "/frame_" + std::to_string(frame) + ".png";
        png.writeToFile(filename);

        zoom *= zoomFactor; // Increase zoom level
    }

    std::cout << "Animation frames saved to " << outputDir << std::endl;
}


