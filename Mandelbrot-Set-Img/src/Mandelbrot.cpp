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

// Convert strings to numbers
int number(char* string) {
    int i = 0, num = 0;

    while (string[i] != NULL) {
        if (string[i] < 48 && string[i] > 57)
            // the string has characters that's not digits
            return -1;
        
        num *= 10;
        num += string[i] - 48;
        
        i++;
    }
    return num;
}

void PrintImage() {
    std::ofstream img("mandelbrot.ppm");
    img << "P3" << std::endl;
    img << WIDTH << " " << HEIGHT << std::endl;
    img << MAX_COLOUR_VALUE << std::endl;

    std::cout << "Printing the image...\n";

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            auto x_coord = float((OFFSET_X + x - 150 - float(WIDTH / 2)) / ZOOM);
            auto y_coord = float((-(OFFSET_Y + y - float(HEIGHT / 2)) / ZOOM));

            std::complex<float> c(x_coord, y_coord);
            int m = Mandelbrot(c);

            int r = m;
            int g = m;
            int b = m;

            img << r << " " << g << " " << b << " ";

        }
        img << std::endl;

    }
    std::cout << "Done printing!\n";
}

void help() {
    std::cout << "Usage:\n";
    std::cout << "Updating...\n";
}

