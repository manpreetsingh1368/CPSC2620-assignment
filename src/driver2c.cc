#include "turtle.h"
#include <algorithm>

using namespace cimg_library;

// draw a tree with length len
void tree(Turtle & t, int len);

int main() {
    // create an image object with black background
  CImg<unsigned char> myimg(800, 600, 1, 3, 0);

    Turtle tt(myimg, 0, -100, 0);
    tree(tt, 100);

    // Display the image in a window
    CImgDisplay main_disp(myimg, "Driver 2a");

    // Keep the window open until the user closes it
    while (!main_disp.is_closed()) {
        main_disp.wait();
    }

    return 0;
}


// Implementation for local functions a la 1620

void tree(Turtle & t, int len) {
	if (len >= 4) {
		Turtle tbak=t;  // save the initial position of the turtle
		t.forward(len);
		t.lt(30);
		tree(t, 4*len/5);
		t.rt(55);
		tree(t, 2*len/3);
		 tbak = tbak; 
  // restore the turtle state
	}
}
