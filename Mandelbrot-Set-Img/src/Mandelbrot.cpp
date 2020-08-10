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

/*int PercentComplete = 0;
int count = 0;  // Count the number of pixel printed
*/

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
    std::cout << "0% completed...\n";

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            std::complex<float> c (float((OFFSET_Y+y-float(WIDTH/2))/ZOOM),
                                float((-(OFFSET_X+x-float(HEIGHT/2))/ZOOM)));
            int m = Mandelbrot(c);

            int r = m;
            int g = m;
            int b = m;

            img << r << " " << g << " " << b << " ";

            /*count++;
            PercentComplete = (count / (512 * 512)) * 100;
            //std::cout << count << "\t" << PercentComplete << std::endl;
            if (PercentComplete == 25) std::cout << "25% completed...\n";
            else if (PercentComplete == 50) std::cout << "50% completed...\n";
            else if (PercentComplete == 75) std::cout << "75% completed...\n";
            else if (PercentComplete == 100) std::cout << "100% completed...\n";*/
        }
        img << std::endl;

    }

    std::cout << "Done printing!\n";
    std::cin.get();
    return 0;
}
