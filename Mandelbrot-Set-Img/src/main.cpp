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
    
    // if the programme takes no arguments
    if (argc < 2) {
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

        PrintImage();
    }
    // The programme has some arguments
    else {
        // Command-line arguments parser
        for (int i = 1; i < argc; i++) {

            // Parse --imgsize option
            if (argv[i] == "--imgsize" || argv[i] == "-i") {

                // if there's no arguments after --imgsize
                if (argv[i + 1] == NULL || argv[i + 2] == NULL) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                int x = number(argv[i + 1]);
                int y = number(argv[i + 2]);

                // if the argument after --imgsize is not number
                if (x == -1) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                // If one argument only is assigned to --imgsize
                // it'll assume that the image is square, has the same
                // WIDTH and HEIGHT
                if (y == -1) {
                    WIDTH = x;
                    HEIGHT = x;
                }
                else {
                    WIDTH = x;
                    HEIGHT = y;
                }
            }

            // Parse --offset option
            if (argv[i] == "--offset" || argv[i] == "-o") {

                // if there's no arguments after --offset
                if (argv[i + 1] == NULL || argv[i + 2] == NULL) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                int x = number(argv[i + 1]);
                int y = number(argv[i + 2]);

                // if the argument after --offset is not number
                if (x == -1) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                // If one argument only is assigned to --offset
                // it'll assume that Offset_X and Offset_Y have
                // the same value
                if (y == -1) {
                    OFFSET_X = x;
                    OFFSET_Y = x;
                }
                else {
                    OFFSET_X = x;
                    OFFSET_Y = y;
                }
            }

            // Parse --maxiter option
            if (argv[i] == "--maxiter" || argv[i] == "-m") {
                // if there's no arguments after --maxiter
                if (argv[i + 1] == NULL) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                int x = number(argv[i + 1]);

                // if the argument after --maxiter is not number
                if (x == -1) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                MAX_ITER = x;
            }

            // Parse --zoom option
            if (argv[i] == "--zoom" || argv[i] == "-z") {
                // if there's no arguments after --zoom
                if (argv[i + 1] == NULL) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                int x = number(argv[i + 1]);

                // if the argument after --zoom is not number
                if (x == -1) {
                    std::cout << "Invalid arguments";
                    return 1;
                }

                ZOOM = x;
            }

            //Parse --help option
            if (argv[i] == "--help" || argv[i] == "-h") help();
        }
        PrintImage();
    }

    // Open the generated image in its associated programme
    // using ShellExecute
    std::cout << "Opening the file...\n";
    ShellExecute(0, 0, L"mandelbrot.ppm", 0, 0, SW_SHOW);

    std::cin.get();
    return 0;
}