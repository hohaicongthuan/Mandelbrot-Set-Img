#include <fstream>
#include <cmath>
#include <complex>
#include <iostream>

// Image size
#define WIDTH 1024
#define HEIGHT 1024
#define MAX_COLOUR_VALUE 255

// The more iterations, the more details the Mandelbrot
// will be, but it'll take longer to calculate
#define MAX_INTER 100

// Change these values to move and zoom the Mandelbrot Set
#define OFFSET_X -10
#define OFFSET_Y 0
#define ZOOM 350

int Mandelbrot(std::complex<float> c) {
    std::complex<float> z (0.0, 0.0);
    int n = 0;

    while (abs(z) <= 2 and n < MAX_INTER) {
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

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            auto x_coord = float((OFFSET_X + x - 150 - float(WIDTH / 2)) / ZOOM);
            auto y_coord = float((-(OFFSET_Y + y - float(HEIGHT / 2)) / ZOOM));
            
            std::complex<float> c (x_coord, y_coord);
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
