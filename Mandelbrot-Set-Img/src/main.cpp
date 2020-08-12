#include "Mandelbrot.h"

/* MORE INFORMATION ABOUT COMMAND LINE ARGUMENTS

    * argc (ARGument Count) is int and stores number of command-line arguments
    passed by the user including the name of the programme. So if we pass a 
    value to a programme, value of argc would be 2 (one for argumentand one
    for programme name)
    * The value of argc should be non negative.
    * argv (ARGument Vector) is array of character pointers listing all the arguments.
    * If argc is greater than zero, the array elements from argv[0] to argv[argc - 1]
    will contain pointers to strings.
    * argv[0] is the name of the programme, After that till argv[argc - 1] every element
    is command-line arguments.
*/

int main(int argc, char* argv[]) {
    int ans;
    do {
        system("cls");
        std::cout << "Default or Manual?\n";
        std::cout << "1. Default: default settings will be used to generate the image.\n";
        std::cout << "2. Manual: manually enter parameters to generate the image.\n";
        std::cout << "Your answer: ";
        std::cin >> ans;
    } while (ans != 1 && ans != 2);
    std::cout << std::endl;

    if (ans == 2) {
        std::cout << "Enter image size X & Y: ";
        std::cin >> WIDTH >> HEIGHT;
        std::cout << "Enter maximum iteration: ";
        std::cin >> MAX_ITER;
        std::cout << "Enter zoom: ";
        std::cin >> ZOOM;
        std::cout << "Enter offset X & Y: ";
        std::cin >> OFFSET_X >> OFFSET_Y;
    }

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

    // Open the generated image in its associated programme
    // using ShellExecute
    std::cout << "Opening the file...\n";
    ShellExecute(0, 0, L"mandelbrot.ppm", 0, 0, SW_SHOW);

    std::cin.get();
    return 0;
}