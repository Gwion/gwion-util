#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "err_msg.h"

#define describe_gw_xxx(name)            \
void gw_##name(const char* fmt, ...) { \
  va_list arg;                           \
  va_start(arg, fmt);                    \
  vfprintf(std##name, fmt, arg);         \
  va_end(arg);                           \
}
describe_gw_xxx(err)
describe_gw_xxx(out)
