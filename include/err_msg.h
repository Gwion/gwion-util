/** @file: err_msg.h
\brief thread-safe console output
**/

#ifndef __ERRMSG
#define __ERRMSG

#include <stdarg.h>
/** similar to fprintf(stderr, fmt, ...) **/
void gw_err(const char* fmt, ...);
/** similar to fprintf(stdout, fmt, ...) **/
void gw_out(const char* fmt, ...);

#ifdef __FUZZING__
#define gw_err(a,...)
#define gw_out(a,...)
#endif

#endif
