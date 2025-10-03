#include "turtle.h"
#include "CImg.h"
#include <iostream>

using namespace cimg_library;

int main() {
    CImg<unsigned char> image(600, 400, 1, 3, 255); // white canvas
    Turtle t(image, 0, 0, 0);
    t.pd(); // pen down
    t.forward(100);
    t.lt(90);
    t.forward(100);
    image.save("multi_turtle_output.png");
    std::cout << "Done drawing multi_turtle_output.png\n";
    return 0;
}
