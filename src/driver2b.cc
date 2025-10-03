#include "turtle.h"

using namespace cimg_library;

struct Point_t {
	int x;
	int y;
};

int main() {
    // create an image object with black background
    CImg<unsigned char> myimg(800, 600, 1, 3, 0);

		const int ptSize=5;
		Point_t ptsA[]={{-100,-50}, {-50,50}, {0,-50}, {50, 50}, {100, -50}};
		Point_t ptsB[]={{-100,50}, {-50,-50}, {0,50}, {50, -50}, {100, 50}};
    Turtle tA(myimg, ptsA[0].x, ptsA[0].y, 0);
		Turtle tB(myimg, ptsB[0].x, ptsB[0].y, 0);

		tA.pd();  tB.pd();
		for (int i=1; i<ptSize; i++) {
			tA.moveTo(ptsA[i].x, ptsA[i].y);
			tB.moveTo(ptsB[i].x, ptsB[i].y);
		}

    // Display the image in a window
    CImgDisplay main_disp(myimg, "Driver 2a");

    // Keep the window open until the user closes it
    while (!main_disp.is_closed()) {
        main_disp.wait();
    }

    return 0;
}
