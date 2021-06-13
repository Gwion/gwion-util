/** @file: err_msg.h
\brief thread-safe console output
**/

#ifndef __ERRMSG
#define __ERRMSG

#include <stdarg.h>
#include <termcolor.h>
/** similar to fprintf(stderr, fmt, ...) **/
#define gw_err(...) tcol_fprintf(stderr, __VA_ARGS__)
/** similar to fprintf(stdout, fmt, ...) **/
#define gw_out(...) tcol_fprintf(stdout, __VA_ARGS__)

#ifdef __FUZZING__
#define gw_err(a, ...)
#define gw_out(a, ...)
#endif

#endif
