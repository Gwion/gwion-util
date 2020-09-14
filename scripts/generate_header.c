/* use this to generate include/generated.h */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#ifdef BUILD_ON_WINDOWS
#define NUSED
#include "windows_missing.h"
#define __USE_MINGW_ANSI_STDIO 1
#ifdef __MINGW64__
#define SIZET_FMT "%tu"
#else
#define SIZET_FMT "%tu"
#endif
#else
#define SIZET_FMT "%zu"
#endif

#ifdef USE_DOUBLE
static const char* type   = "double";
#define SZ sizeof(double)
#else
static const char* type   = "float ";
#define SZ sizeof(float)
#endif

static void doc(void) {
  puts("/** @file: generated.h\n\\brief basic common includes and types.\n*/");
}

static void include(void) {
  puts("#include <stddef.h>\n#include <stdlib.h>\n#include <inttypes.h>\n#include <float.h>");
#ifdef USE_DOUBLE
  puts("#define GWION_EPSILON DBL_EPSILON");
#else
  puts("#define GWION_EPSILON FLT_EPSILON");
#endif
#ifdef BUILD_ON_WINDOWS
  puts("#include \"windows_missing.h\"");
#endif
}

static void base_type(void) {
  printf("/* common typedefs */\ntypedef intptr_t m_int;\n"
      "typedef uintptr_t m_uint;\ntypedef unsigned char m_bit;\n"
      "typedef int m_bool;\ntypedef %s m_float;\ntypedef char * m_str;\n",
      type);
}

static void compound_type(void) {
  printf("typedef struct { m_float x, y, z; } m_vec3;\n"
      "typedef struct { m_float x, y, z, w; } m_vec4;\n"
      "typedef _Complex %s m_complex;\n", type);
}

static void size(void) {
  printf("#define SZ_INT     " SIZET_FMT "\n"
         "#define SZ_FLOAT   " SIZET_FMT "\n"
         "#define SZ_COMPLEX " SIZET_FMT "\n"
         "#define SZ_VEC3    " SIZET_FMT "\n"
         "#define SZ_VEC4    " SIZET_FMT "\n",
    sizeof(uintptr_t), SZ, SZ * 2, SZ * 3, SZ * 4);
}

static void format(void) {
#ifndef BUILD_ON_WINDOWS
  puts("#define  INT_F \"ti\"\n#define UINT_F \"tu\"\n#define abs labs");
#else
  if(sizeof(uintptr_t) == sizeof(unsigned long int))
    puts("#define  INT_F \"li\"\n#define UINT_F \"lu\"\n#define abs labs");
  else if(sizeof(uintptr_t) == sizeof(unsigned long long int))
    puts("#define  INT_F \"lli\"\n#define UINT_F \"llu\"\n#define abs llabs");
  else
    puts("#define  INT_F \"i\"\n#define UINT_F \"u\"\n#define abs abs");
#endif
}

/*
static void math_func(void) {
  puts("#define creal crealf\n#define cimag cimagf\n#define fabs fabsf"
      "\n#define cos cosf\n#define sin sinf\n#define tan tanf\n"
      "#define acos acosf\n#define asin asinf\n#define atan atanf\n"
      "#define cosh coshf\n#define sinh sinhf\n#define tanh tanhf\n"
      "#define acosh acoshf\n#define asinh asinhf\n#define atanh atanhf\n"
      "#define atan2 atan2f\n#define hypot hypotf\n#define pow powf\n"
      "#define sqrt sqrtf\n#define exp expf\n#define log logf\n"
      "#define log2 log2f\n#define log10 log10f\n#define floor floorf\n"
      "#define ceil ceilf\n#define round roundf\n#define trunc truncf\n"
      "#define fmod fmodf\n#define remainder remainderf");
}
*/
static void minval(void) {
  if(sizeof(uintptr_t) > SZ)
    puts("#define SZ_MINVAL SZ_INT");
  else
    puts("#define SZ_MINVAL SZ_FLOAT");
}

int main(void) {
  doc();
  include();
  base_type();
  compound_type();
  size();
  format();
//  if(strcmp(type, "double"))
//    math_func();
  minval();
  return 0;
}
