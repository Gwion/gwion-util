#include "gwion_util.h"

ANN2(1) static int fmtlen(const char *fmt, va_list args) {
  va_list tmpa;
  va_copy(tmpa, args);
  const int size = vsnprintf(NULL, 0, fmt, tmpa);
  va_end(tmpa);
  return size;
}

ANN2(2)
static int gw_vasprintf(MemPool mp, char **str, const char *fmt, va_list args) {
  char *       base     = *str;
  const size_t base_len = base ? strlen(base) : 0;
  DECL_BB(const int, size, = fmtlen(fmt, args));
  char *ret = mp_malloc2(mp, base_len + size + 1);
  if (base) strcpy(ret, base);
  const int final_len = vsprintf(ret + base_len, fmt, args);
  if (final_len < 0) {
    mp_free2(mp, base_len + size + 1, ret);
    return -1;
  }
  if (base) mp_free2(mp, strlen(base), base);
  *str = ret;
  return final_len;
}

ANN2(2) int gw_asprintf(MemPool mp, char **str, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  const int ret = gw_vasprintf(mp, str, fmt, args);
  va_end(args);
  return ret;
}
