#include <iostream>
#include <stdlib.h>

#include "intro.h"
#include "RGBA/png.h"

#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        // Generate a single Mandelbrot image
        unsigned int width = (unsigned int)atoi(argv[1]);
        std::cout << "Calling myArt(" << width << ", " << width << ") and saving it as `art.png`." << std::endl;

        // Default parameters for a single image
        double zoom = 200.0;
        double zoomCenterX = -0.75; // X-coordinate of the zoom center
        double zoomCenterY = 0.1;   // Y-coordinate of the zoom center
        int maxIterations = 500;    // Maximum iterations

        PNG png = myArt(width, width, zoom, zoomCenterX, zoomCenterY, maxIterations);
        png.writeToFile("art.png");
    } else if (argc == 3 && std::string(argv[1]) == "zoom") {
        // Generate a zoom animation
        unsigned int width = (unsigned int)atoi(argv[2]);
        std::string outputDir = "zoom_animation"; // Output directory
        std::cout << "Generating zoom animation with width = " << width << "..." << std::endl;

        generateZoomAnimation(width, width, outputDir);
    } else {
        // Default behavior (rotate an image)
        std::cout << "Rotating `in_reindeer.png` as `out_reindeer_x.png`" << std::endl;
        rotate("in_reindeer.png", "out_reindeer_x.png");
    }

    return 0;
}
// diff out_reindeer.png out_reindeer_x.png
// ffmpeg -framerate 10 -i frame_%d.png -c:v libx264 -pix_fmt yuv420p zoom_animation.mp4