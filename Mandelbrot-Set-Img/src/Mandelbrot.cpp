#include <fstream>
#include <cmath>
#include <complex>
#include <iostream>

#define WIDTH 512
#define HEIGHT 512
#define MAX_COLOUR_VALUE 255
#define MAX_INTER 500

#define OFFSET_X 0
#define OFFSET_Y 0
#define ZOOM 500

int Mandelbrot(std::complex<float> c) {
    std::complex<float> z (0.0, 0.0);
    int n = 0;

    while  (abs(z) <= 2 and n < MAX_INTER) {
        z = z * z + c;
        n++;
    }
    if (n < MAX_INTER) return 255;
    else return 0;
}

int main() {
    std::ofstream img("mandelbrot.ppm");
    img << "P3" << std::endl;
    img << WIDTH << " " << HEIGHT << std::endl;
    img << MAX_COLOUR_VALUE << std::endl;

    std::cout << "Printing the image...\n";

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            std::complex<float> c (float((OFFSET_Y+y-float(WIDTH/2))/ZOOM),
                                float((-(OFFSET_X+x-float(HEIGHT/2))/ZOOM)));
            int m = Mandelbrot(c);

            int r = m;
            int g = m;
            int b = m;

            img << r << " " << g << " " << b << " ";
        }
        img << std::endl;
    }

    std::cout << "Done printing!\n";
    std::cin.get();
    return 0;
}
