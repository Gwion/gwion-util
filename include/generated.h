#include <stdlib.h>
#include <inttypes.h>
/* common typedefs */
typedef intptr_t m_int;
typedef uintptr_t m_uint;
typedef unsigned char m_bit;
typedef int m_bool;
typedef float  m_float;
typedef char * m_str;
typedef struct { m_float x, y, z; } m_vec3;
typedef struct { m_float x, y, z, w; } m_vec4;
typedef _Complex float  m_complex;
#define SZ_INT     8
#define SZ_FLOAT   4
#define SZ_COMPLEX 8
#define SZ_VEC3    12
#define SZ_VEC4    16
#define  INT_F "li"
#define UINT_F "lu"
#define abs labs
#define creal crealf
#define cimag cimagf
#define fabs fabsf
#define cos cosf
#define sin sinf
#define tan tanf
#define acos acosf
#define asin asinf
#define atan atanf
#define cosh coshf
#define sinh sinhf
#define tanh tanhf
#define acosh acoshf
#define asinh asinhf
#define atanh atanhf
#define atan2 atan2f
#define hypot hypotf
#define pow powf
#define sqrt sqrtf
#define exp expf
#define log logf
#define log2 log2f
#define log10 log10f
#define floor floorf
#define ceil ceilf
#define round roundf
#define trunc truncf
#define fmod fmodf
#define remainder remainderf
#define SZ_MINVAL SZ_INT