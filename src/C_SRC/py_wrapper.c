#include <Python.h>
#include <stdio.h>

PyObject* add(PyObject* self, PyObject* args) {
	int x;
	int y;
	PyArg_ParseTuple(args, "ii", &x, &y);
	return PyLong_FromLong(x + y);
}

static PyMethodDef methods[] = {
	{"add", add, METH_VARARGS, ""},
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
