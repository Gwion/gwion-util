#ifndef __PP
#define __PP
#include <setjmp.h>
typedef struct PP_ {
  struct Vector_ filename;
  struct Hash_* macros;
  struct Macro_* entry;
  struct pp_info def;
  size_t arg_len, arg_cap;
  int npar;
  unsigned lint : 1;
} PP;

ANN Ast parse(struct Scanner_*, const m_str, FILE*);
ANEW Scanner* new_scanner(const uint size);
ANN void free_scanner(Scanner* scan);
ANN void scanner_post(Scanner* scan);
uint clear_buffer(Vector, void*, const m_bool);
#endif
