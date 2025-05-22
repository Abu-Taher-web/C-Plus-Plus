/**
 * @file rgbapixel.h
 * Definition of the RGBAPixel class for the EasyPNG library.
 *
 * @author Chase Geigle
 * @author Anna LaValle
 * @date Created: Spring 2012
 * @date Modified: Spring 2025
 */
#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H
#include <stdint.h>
#include <cstdint>
using std::uint8_t;
// Your code here
class RGBAPixel {
    public:
        uint8_t red;    // Intensity of the red color channel (0-255)
        uint8_t green;  // Intensity of the green color channel (0-255)
        uint8_t blue;   // Intensity of the blue color channel (0-255)
        uint8_t alpha;  // Alpha value (0 = fully transparent, 255 = fully opaque)
    
        // Default constructor
        RGBAPixel();
    
        // Parameterized constructor
        RGBAPixel(uint8_t _r, uint8_t _g, uint8_t _b);
    };
    
#endif

