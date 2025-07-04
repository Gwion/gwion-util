/** @file: windows_missing.h
\brief implementation of function not present in windows
**/
#pragma once
#include <windows.h>
#include <stddef.h>

// needed for clang
#ifndef PATH_MAX
#ifndef MAX_PATH
#define MAX_PATH 260
#endif
#define PATH_MAX MAX_PATH
#endif

typedef unsigned int uint;
char *               strdup(const char *s);
char *               strndup(const char *s, size_t n);
char *               strsep(char **stringp, const char *delim);
int                  getline(char **lineptr, size_t *n, FILE *fp);
FILE *               fmemopen(void *buf, size_t len, const char *type NUSED);
#define realpath(N,R) _fullpath((R),(N),_MAX_PATH)
#ifdef __clang__
#define strdup _strdup

#ifdef USE_DOUBLE
#define creal(a) creal(*(_Dcomplex *)&a)
#define cimag(a) cimag(*(_Dcomplex *)&a)
#else
#define crealf(a) crealf(*(_Fcomplex *)&a)
#define cimagf(a) cimagf(*(_Fcomplex *)&a)
#endif
#endif
