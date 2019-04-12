#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "err_msg.h"

#define describe_gw_xxx(name)            \
m_bool gw_##name(const char* fmt, ...) { \
  va_list arg;                           \
  va_start(arg, fmt);                    \
  vfprintf(std##name, fmt, arg);         \
  va_end(arg);                           \
  return GW_ERROR;                             \
}
describe_gw_xxx(err)
describe_gw_xxx(out)

m_bool err_msg(loc_t pos, const char* fmt, ...) {
  if(pos)
    fprintf(stderr, "line: %u\t", pos);
  else
    fprintf(stderr, "\t");
  va_list arg;
  va_start(arg, fmt);
  vfprintf(stderr, fmt, arg);
  va_end(arg);
  fprintf(stderr, "\n");
  return GW_ERROR;
}

