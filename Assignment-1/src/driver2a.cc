#include "turtle.h"
#include <algorithm>

using namespace cimg_library;

// draw a dashed line with length len
void dashed(Turtle & t, int len);

int main() {
    // create an image object with black background
    CImg<unsigned char> myimg(800, 600, 1, 3, 0);

    Turtle tt(myimg, -100, -100, 0);
		for (int i=0; i<4; i++) {
			dashed(tt, 200);
			// tt.fd(200);
			tt.rt(90);
		}

    // Display the image in a window
    CImgDisplay main_disp(myimg, "Driver 2a");

    // Keep the window open until the user closes it
    while (!main_disp.is_closed()) {
        main_disp.wait();
    }

    return 0;
}


// Implementation for local functions ala 1620

void dashed(Turtle & t, int len) {
	// assuming break between dashes is also <len>
	int dashlen = 5;
	
	for (int i=0; i<len/dashlen/2; i++) {
		t.pd();
		t.forward(dashlen);
		t.pu();
		t.forward(dashlen);
	}

	// our <len> may not be a multiple of 2*<dashlen> 
	int remnder = len%(2*dashlen);
	t.pd();
	t.forward(std::min(dashlen, remnder));
	t.pu();
	t.forward(std::max(0, remnder-dashlen));
	t.pd();
}
