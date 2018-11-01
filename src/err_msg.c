#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "err_msg.h"

//    fprintf(stderr, " \033[4mline \033[1m%" INT_F "\033[0m\t", pos);
m_bool err_msg(m_uint pos, const char* fmt, ...) {
  va_list arg;
  va_start(arg, fmt);
  if(pos > 0)
    fprintf(stderr, " line: %" INT_F "\t", pos);
  else
    fprintf(stderr, "\t");
  vfprintf(stderr, fmt, arg);
  fprintf(stderr, "\n");
  va_end(arg);
  return -1;
}

#define describe_gw_xxx(name)            \
m_bool gw_##name(const char* fmt, ...) { \
  va_list arg;                           \
  va_start(arg, fmt);                    \
  vfprintf(std##name, fmt, arg);         \
  va_end(arg);                           \
  return -1;                             \
}
describe_gw_xxx(err)
describe_gw_xxx(out)
