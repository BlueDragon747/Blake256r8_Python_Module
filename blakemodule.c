#include <Python.h>

#include "blake.h"

static PyObject *blake_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    blake_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    blake_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef BlakeMethods[] = {
    { "getPoWHash", blake_getpowhash, METH_VARARGS, "Returns the proof of work hash using blake hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef BlakeModule = {
    PyModuleDef_HEAD_INIT,
    "blake_hash",
    "...",
    -1,
    BlakeMethods
};

PyMODINIT_FUNC PyInit_blake_hash(void) {
    return PyModule_Create(&BlakeModule);
}

#else

PyMODINIT_FUNC initblake_hash(void) {
    (void) Py_InitModule("blake_hash", BlakeMethods);
}
#endif
