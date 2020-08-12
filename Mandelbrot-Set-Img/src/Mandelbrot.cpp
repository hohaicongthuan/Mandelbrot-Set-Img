#include "Mandelbrot.h"

// Image size
int WIDTH = 1024;
int HEIGHT = 1024;
int MAX_COLOUR_VALUE = 255;

// The more iterations, the more details the Mandelbrot
// will be, but it'll take longer to calculate
int MAX_ITER = 100;

// Change these values to move and zoom the Mandelbrot Set
int OFFSET_X = -10;
int OFFSET_Y = 0;
int ZOOM = 350;

int Mandelbrot(std::complex<float> c) {
    std::complex<float> z (0.0, 0.0);
    int n = 0;

    while (abs(z) <= 2 and n < MAX_ITER) {
        z = z * z + c;
        n++;
    }
    if (n < MAX_ITER) return 255;
    else return 0;
}

