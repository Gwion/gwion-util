#ifndef __ERRMSG
#define __ERRMSG

#include <stdarg.h>
void gw_err(const char* fmt, ...);
void gw_out(const char* fmt, ...);

#ifdef __FUZZING__
#define gw_err(a,...)
#define gw_out(a,...)
#endif

#endif
