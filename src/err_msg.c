#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "err_msg.h"

static const char* err_headers[] = { "PARSE", "SCAN0", "SCAN1", "SCAN2_", "CHECK", "EMIT!", "UTILS", "LEXER",
                                     "INSTR", "ALSA", " VM  ", " OP  "

};

m_bool err_msg(a_header header, m_uint pos, const char* fmt, ...) {
  va_list arg;
  va_start(arg, fmt);
#ifdef COLOR
  fprintf(stderr, "\033[1m[\033[0m\033[31m%s\033[0m\033[1m]\033[0m", err_headers[header]);
#else
  fprintf(stderr, "%s", err_headers[header]);
#endif
  if(pos > 0)
#ifdef COLOR
    fprintf(stderr, " \033[4mline \033[1m%" INT_F "\033[0m\t", pos);
#else
    fprintf(stderr, " line: %" INT_F "\t", pos);
#endif
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
