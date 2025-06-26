/** @file: generated.h
\brief basic common includes and types.
*/
#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <inttypes.h>
#include <float.h>
#define GWION_EPSILON FLT_EPSILON
/* common typedefs */
typedef intptr_t m_int;
typedef uintptr_t m_uint;
typedef unsigned char m_bit;
typedef float  m_float;
typedef char * m_str;
typedef struct { m_float x, y, z; } m_vec3;
typedef struct { m_float x, y, z, w; } m_vec4;
typedef _Complex float  m_complex;
#define SZ_INT     sizeof(m_uint)
#define SZ_FLOAT   sizeof(m_float)

#define  INT_F "ti"
#define UINT_F "tu"
#define abs labs

/*
#if sizeof(m_uint) > sizeof(m_float)
#define SZ_MINVAL SZ_INT
#else
#define SZ_MINVAL SZ_FLOAT
#endif
*/
