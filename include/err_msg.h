#ifndef __ERRMSG
#define __ERRMSG

#include <stdarg.h>
m_bool gw_err(const char* fmt, ...);
m_bool gw_out(const char* fmt, ...);
#define GWDEBUG_EXE

#endif
