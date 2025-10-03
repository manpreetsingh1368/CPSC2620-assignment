#include "turtle.h"
#include "CImg.h"
#include <iostream>

using namespace cimg_library;

int main() {
    CImg<unsigned char> image(600, 400, 1, 3, 255); // white canvas
    Turtle t(image, -100, 0, 0); // start left of center, facing right

    t.pd();          // Pen down
    t.forward(50);   // Draw line

    t.pu();          // Lift pen
    t.rt(45);        // Turn down-right
    t.forward(50);   // No line

    t.pd();          // Pen down again
    t.rt(45);        // Now facing down
    t.forward(50);   // Draw line

    t.pu();
    t.lt(90);        // Turn back left
    t.forward(50);   // No line

    image.save("zigzag_test.png");
    std::cout << "Saved zigzag_test.png\n";

    return 0;
}
