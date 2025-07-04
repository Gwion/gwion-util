/** @file symbol.h
\brief Symbol table
**/
#pragma once

#include "gwion_thread.h"
typedef struct Symbol_ *Symbol;
struct Symbol_ {
  Symbol next;
  char   name[];
};
typedef struct SymTable_ {
  gwtlock_t mutex;
  MemPool   p;
  size_t    sz;
  Symbol    sym[];
} SymTable;

ANN SymTable *new_symbol_table(MemPool p, const size_t sz);
ANN Symbol    insert_symbol(SymTable *const, const m_str) __attribute__((pure));

__attribute__((pure)) ANN static inline m_str s_name(const Symbol s) {
  return s->name;
};
ANN void free_symbols(SymTable *const);
