#include "turtle.h"
#include "CImg.h"
#include <iostream>

using namespace cimg_library;

int main() {
    // Create a 600x400 white canvas
    CImg<unsigned char> image(600, 400, 1, 3, 255); // white background

    // Create turtle at center, facing right (0 degrees)
    Turtle t(image, 0, 0, 0);

    // Put pen down to start drawing
    t.pd();

    // Draw rectangle with width 100 and height 50
    t.forward(100);   // Right
    t.rt(90);
    t.forward(50);    // Down
    t.rt(90);
    t.forward(100);   // Left
    t.rt(90);
    t.forward(50);    // Up

    // Save result to file
    image.save("rectangle.png");
    std::cout << "Saved rectangle.png\n";
    return 0;
}
