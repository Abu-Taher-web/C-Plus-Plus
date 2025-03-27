# Image Processing with C++

## Overview
This project is a lightweight yet powerful C++ image processing tool designed for developers and engineers working with images at the pixel level. It provides three essential functions:
- **Image Overlay**: Merges two images, handling transparency with RGBA pixel manipulation.
- **Brightness Adjustment**: Increases the brightness of an image by modifying pixel intensity.
- **Crosshair Generator**: Overlays a crosshair at a specified coordinate for targeting or visualization purposes.

## Features
- **Efficient Pixel Processing**: Uses `png.h` for PNG decoding and encoding.
- **RGBA Pixel Manipulation**: Enables precise control over transparency and color.
- **Optimized Algorithm**: Uses `std::algorithm` for efficient operations.
- **Portable**: Can be easily integrated into embedded systems and industrial applications.

## Technologies Used
- **C++ (Standard Libraries)**
- **PNG Handling**: `png.h` for image decoding and encoding.
- **Custom RGBAPixel Class**: Designed to manage pixel-level modifications.

## Dependencies
Ensure you have the following installed:
- **GCC Compiler** (C++17 or later recommended)
- **libpng** (for `png.h` support)

## Installation
```bash
# Clone the repository
git clone https://github.com/yourusername/image-processing-cpp.git
cd image-processing-cpp

# Build the project
make
```

## Usage
```cpp
#include "png.h"
#include "rgbapixel.h"

int main()
{
    // Open a new PNG image from the file sample.png.
    PNG image("sample.png");
    cout<<"image height:"<<image.height()<<" "<<"Image width:"<< image.width()<<"\n";
    RGBAPixel* x = &image(1, 1);
    int r = x->red;
    int g = x->green;
    int b = x->blue;
    int alpha = x->alpha;
    cout<<"r:"<< r <<endl;
    cout<<"g:"<< g <<endl;
    cout<<"b:"<< b <<endl;
    cout<<"alpha:"<< alpha <<endl;
    // Open a new PNG image from the file overlay.png.
    PNG overlay("overlay.png");

    // Brighten the image read from overlay.png.
    brighten(overlay, 128);

    // Blend sample.png and overlay.png together.
    blendImages(image, overlay);

    // Create a new RGBAPixel color for drawCrosshairs which is cyan.
    RGBAPixel cyanColor(0, 255, 255);

    // Draw two crosshairs on the image.
    drawCrosshairs(image, 460, 305, cyanColor);
    drawCrosshairs(image, 676, 410, cyanColor);

    image.resize(795,595);

    // Save the modified image to a file called output.png, overwriting the file
    // if it already exists.
    image.writeToFile("output.png");

    return 0;
}
```

## Applications
- **Embedded Systems**: Can be integrated into vision-based embedded applications.
- **Industrial Automation**: Useful for image pre-processing in automation systems.
- **Augmented Reality (AR) and Defense**: Can be leveraged in targeting and object-tracking applications.



