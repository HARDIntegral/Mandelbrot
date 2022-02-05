#include "mandelbrot.h"

PyObject* plot(PyObject* self, PyObject* args) {
	int width;
	int height;
	int granularity;
	if (!PyArg_ParseTuple(args, "iii", &width, &height, &granularity))
		return NULL;

	return __plot_mandel(width, height, granularity);
}

static PyMethodDef methods[] = {
	{"plot", plot, METH_VARARGS, ""},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef py_mand = {
	PyModuleDef_HEAD_INIT,
	"py_mand",
	"C interop to plot the Mandelbrot Set",
	-1,
	methods
};

PyMODINIT_FUNC PyInit_py_mand() {
	return PyModule_Create(&py_mand);
}
