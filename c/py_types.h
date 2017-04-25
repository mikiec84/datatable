#ifndef dt_PY_TYPES_H
#define dt_PY_TYPES_H
#include <Python.h>
#include "types.h"
#include "datatable.h"

#if LLONG_MAX==9223372036854775807
    // int64_t == long long int
    #define PyLong_AsInt64             PyLong_AsLongLong
    #define PyLong_AsInt64AndOverflow  PyLong_AsLongLongAndOverflow
    #define PyLong_AsUInt64            PyLong_AsUnsignedLongLong
    #define PyLong_AsUInt64Mask        PyLong_AsUnsignedLongLongMask
#elif LONG_MAX==9223372036854775807
    // int64_t == long int
    #define PyLong_AsInt64             PyLong_AsLong
    #define PyLong_AsInt64AndOverflow  PyLong_AsLongAndOverflow
    #define PyLong_AsUInt64            PyLong_AsUnsignedLong
    #define PyLong_AsUInt64Mask        PyLong_AsUnsignedLongMask
#else
    #error "Bad architecture: int64_t not available..."
#endif


typedef PyObject* (stype_formatter)(Column *col, int64_t row);

extern PyObject* py_ltype_names[DT_LTYPES_COUNT];
extern PyObject* py_stype_names[DT_STYPES_COUNT];
extern stype_formatter* py_stype_formatters[DT_STYPES_COUNT];


int init_py_types(PyObject *module);

#endif