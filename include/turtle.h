#ifndef TURTLE_H
#define TURTLE_H

#include "CImg.h"     // CImg library for image handling
#include <utility> 
#include <cmath>      // for std::pair
#include <functional> // for std::reference_wrapper

using namespace cimg_library; //  use CImg directly
using namespace std;


class Turtle {
private:
    // Use reference_wrapper to allow copy
    std::reference_wrapper<CImg<unsigned char>> image;

    // Turtle's position and angle (in degrees)
    int x, y;
    float angle;

    // If true, the pen is down and draws when the turtle moves
    bool penDown;

public:
    // Constructor: set image, starting position and angle
    Turtle(CImg<unsigned char>& img, int startX, int startY, int startAngle);

    // Turn the turtle left by given degrees
    void lt(int degrees);

    // Turn the turtle right by given degrees
    void rt(int degrees);

    // Lift the pen up (stop drawing)
    void pu();

    // Put the pen down (start drawing)
    void pd();

    // Move the turtle to a specific (x, y) position
    void moveTo(int newX, int newY);

    // Move the turtle forward by a certain distance
    void forward(int distance);

    // Check if the pen is down
    bool isPenDown() const { return penDown; }

    // Set the pen down or up
    void setPenDown(bool down) { penDown = down; }

private:
    // Draw a line from (x0, y0) to (x1, y1)
    void drawLine(int x0, int y0, int x1, int y1);

    // Convert turtle coordinates to image coordinates
    std::pair<int, int> toImageCoords(int xt, int yt);
};

#endif // TURTLE_H
