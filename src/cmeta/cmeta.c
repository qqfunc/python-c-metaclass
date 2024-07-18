#define PY_SSIZE_T_CLEAN
#include <Python.h>

typedef struct {
    PyTypeObject type;
    int value;
} MetaObject;

PyTypeObject MetaObjectType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cmeta.MetaObject",
    .tp_basicsize = sizeof(MetaObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
};

typedef struct {
    PyObject_HEAD
} MyObject;

PyTypeObject MyObjectType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cmeta.MyObject",
    .tp_basicsize = sizeof(MyObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
};

typedef struct {
    PyObject_HEAD
} ThirdObject;

static PyObject *
ThirdObject_value(ThirdObject *self, void *Py_UNUSED(closure)) {
    return PyLong_FromLong(0);
}

static PyGetSetDef ThirdObject_getset[] = {
    {
        "value", (getter) ThirdObject_value, NULL,
        PyDoc_STR("The value of the ThirdObject."), NULL
    },
    {NULL},
};

PyTypeObject ThirdObjectType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cmeta.ThirdObject",
    .tp_basicsize = sizeof(ThirdObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_getset = ThirdObject_getset,
    .tp_new = PyType_GenericNew,
};

static PyModuleDef cmetamodule = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "cmeta",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_cmeta(void)
{
    PyObject *module;

    module = PyModule_Create(&cmetamodule);
    if (module == NULL) {
        return NULL;
    }

    MetaObjectType.tp_base = &PyType_Type;
    PyModule_AddType(module, &MetaObjectType);
    Py_XDECREF(&MetaObjectType);

    Py_SET_TYPE(&MyObjectType, &MetaObjectType);
    ((MetaObject*) &MyObjectType)->value = 0;
    PyModule_AddType(module, &MyObjectType);
    Py_XDECREF(&MyObjectType);

    PyModule_AddType(module, &ThirdObjectType);
    Py_XDECREF(&ThirdObjectType);

    return module;
}
