#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "gwion_thread.h"
typedef struct Symbol_ * Symbol;
typedef struct SymTable_ {
  Symbol *sym;
  size_t sz;
  MUTEX_TYPE mutex;
} SymTable;

ANN SymTable* new_symbol_table(size_t sz);
ANN Symbol insert_symbol(SymTable*, const m_str) __attribute__((pure));
ANN m_str s_name(const Symbol) __attribute__((pure));
ANN void free_symbols(SymTable*);
ANN void did_you_mean(SymTable*, const char* name);
#endif
