#pragma once

#include <fstream>
#include <cmath>
#include <complex>
#include <iostream>
#include <Windows.h>

// Image size
extern int WIDTH;
extern int HEIGHT;
extern int MAX_COLOUR_VALUE;

// The more iterations, the more details the Mandelbrot
// will be, but it'll take longer to calculate
extern int MAX_ITER;

// Change these values to move and zoom the Mandelbrot Set
extern int OFFSET_X;
extern int OFFSET_Y;
extern int ZOOM;

int Mandelbrot(std::complex<float> c);
int number(char* string);
void PrintImage();
void help(); // Show help for --help option