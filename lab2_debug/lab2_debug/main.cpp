
#include <iostream>
#include <memory>
#include "png.h"

std::unique_ptr<PNG> colorize(std::unique_ptr<PNG> original);
std::unique_ptr<PNG> addBorders(std::unique_ptr<PNG> original);
std::unique_ptr<PNG> sketchify(std::unique_ptr<PNG> original);
void processImage();

int main()
{
    PNG input_image("in_01.png");
    std::cout<<"Input image width: "<<input_image.width()<<" Height: "<<input_image.height()<<std::endl;
     try {
	std::cout << "Reached line " <<__LINE__ <<" File Name:"<< __FILE__ << std::endl;
        processImage();
	std::cout << "Reached line " <<__LINE__ <<" File Name:"<< __FILE__ << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
     
}
