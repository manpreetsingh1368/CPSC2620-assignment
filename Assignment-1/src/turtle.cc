// turtle.cc
#include "turtle.h"
#include <cmath>

// Constructor
Turtle::Turtle(CImg<unsigned char>& img, int px, int py, int ang)
    : image(img), x(px), y(py), angle(ang), penDown(true) {}

// Turn left
void Turtle::lt(int degrees) {
    angle += degrees;
    angle = fmod(angle, 360.0);
}

// Turn right
void Turtle::rt(int degrees) {
    angle -= degrees;
    angle = fmod(angle + 360.0, 360.0);
}

// Pen up
void Turtle::pu() {
    penDown = false;
}

// Pen down
void Turtle::pd() {
    penDown = true;
}

// Move to (x, y)
void Turtle::moveTo(int newX, int newY) {
    if (penDown) {
        drawLine(x, y, newX, newY);
    }
    x = newX;
    y = newY;
}

// Move forward
void Turtle::forward(int distance) {
    int newX = x + static_cast<int>(distance * cos(angle * M_PI / 180.0));
    int newY = y + static_cast<int>(distance * sin(angle * M_PI / 180.0));
    moveTo(newX, newY);
}

// Convert Turtle coords to image coords
std::pair<int, int> Turtle::toImageCoords(int xt, int yt) {
    int xi = image.get().width() / 2 + xt;
    int yi = image.get().height() / 2 - yt;
    return {xi, yi};
}

// Draw line on image
void Turtle::drawLine(int x0, int y0, int x1, int y1) {
    auto [xi0, yi0] = toImageCoords(x0, y0);
    auto [xi1, yi1] = toImageCoords(x1, y1);
    const unsigned char color[] = {0,0,0}; // black
image.get().draw_line(xi0, yi0, xi1, yi1, color);

}
