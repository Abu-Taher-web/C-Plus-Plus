#pragma once

#include "RGBA/png.h"

#include <string>

void rotate(const std::string & inputFile, const std::string & outputFile);
//PNG myArt(unsigned int width, unsigned int height);
PNG myArt(unsigned int width, unsigned int height, double zoom, double zoomCenterX, double zoomCenterY, int maxIterations);
void generateZoomAnimation(unsigned int width, unsigned int height, const std::string &outputDir);
