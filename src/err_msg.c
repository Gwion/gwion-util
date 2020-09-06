#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "err_msg.h"
#include "gwion_thread.h"
#include "xalloc.h"

#ifndef __FUZZING__

static MUTEX_TYPE mutex_err;
static MUTEX_TYPE mutex_out;
__attribute__((constructor))
static void setup() {
  MUTEX_SETUP(mutex_err);
  MUTEX_SETUP(mutex_out);
}
__attribute__((destructor))
static void cleanup() {
  MUTEX_CLEANUP(mutex_err);
  MUTEX_CLEANUP(mutex_out);
}

#define describe_gw_xxx(name)            \
void gw_##name(const char* fmt, ...) {   \
  MUTEX_LOCK(mutex_##name);              \
  va_list arg;                           \
  va_start(arg, fmt);                    \
  vfprintf(std##name, fmt, arg);         \
  va_end(arg);                           \
  MUTEX_UNLOCK(mutex_##name);            \
}
describe_gw_xxx(err)
describe_gw_xxx(out)

#endif
