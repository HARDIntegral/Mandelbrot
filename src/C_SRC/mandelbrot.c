#include "mandelbrot.h"
#include "prog_bar.h"
#include <complex.h>
#include <time.h>

PyObject* __calc_row(double complex* comp, int granularity, int width) {
	PyObject* row = PyList_New(0);

	for (double x=0; x<width; x++) {
		int val = 0;
		__real__ *comp = -2 + (x/width)*3;
		for(double complex z = 0+0*I; cabs(z)<2 && val<granularity; val++)
			z = z*z + *comp;
		PyList_Append(row, PyLong_FromLong(255 - (val*5)%255));
	}

	return row;
}

PyObject* __plot_mandel(int width, int height, int granularity) {
	PyObject* pixels = PyList_New(0);
	double complex comp;
	clock_t start = clock();
	for(double y=0; y<height; y++) {
		__imag__ comp = -1 + (y/height)*2;
		PyList_Append(pixels, __calc_row(&comp, granularity, width));
		update_bar(y, height);
		printf("\033[2F");
	}
	clock_t end = clock();
	update_bar(height, height);
	printf("Elapsed time: %f s\n", (double)(end-start)/CLOCKS_PER_SEC);
	return pixels;
}
