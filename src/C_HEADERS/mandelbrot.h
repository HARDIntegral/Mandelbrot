#ifndef __MANDELBROT_H_
#define __MANDELBROT_H_

#include <Python.h>

PyObject* __plot_mandel(int width, int height, int granularity);

#endif /* __MANDELBROT_H_ */
