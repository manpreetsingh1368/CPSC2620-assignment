#include "turtle.h"

using namespace cimg_library;

int main() {
    // create an image object with black background
    CImg<unsigned char> myimg(800, 600, 1, 3, 0);

    Turtle tt(myimg, -100, 0, 45);
    Turtle tt2(myimg, 100, 0, 360-45);
    tt.forward(141);
    tt2.forward(141);

    // Display the image in a window
    CImgDisplay main_disp(myimg, "Driver 1a");

    // Keep the window open until the user closes it
    while (!main_disp.is_closed()) {
        main_disp.wait();
    }

    return 0;
}