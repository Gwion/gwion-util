#include <stdlib.h>
#include <string.h>
#include "gwion_util.h"

#ifdef min
#undef min
#endif

#define MAX_DISTANCE 2
#define min2(a, b) ((a) < (b) ? (a) : (b))
#define min(a, b, c) (min2(min2((a), (b)), (c)))

ANN SymTable* new_symbol_table(MemPool p, size_t sz) {
  SymTable *st = mp_malloc2(p, sizeof(struct SymTable_));
  st->sz = sz;
  st->sym = (Symbol*)xcalloc(sz, sizeof(struct Symbol_*));
  MUTEX_SETUP(st->mutex);
  st->p = p;
  return st;
}

ANN static void free_symbol(MemPool p, const Symbol s) {
  if(s->next)
    free_symbol(p, s->next);
  free_mstr(p, s->name);
  mp_free(p, Symbol, s);
}

void free_symbols(SymTable* ht) {
  LOOP_OPTIM
  for(uint i = ht->sz + 1; --i;) {
    const Symbol s = ht->sym[i - 1];
    if(s)
      free_symbol(ht->p, s);
  }
  xfree(ht->sym);
  MUTEX_CLEANUP(ht->mutex);
  mp_free(ht->p, SymTable, ht);
}

__attribute__((hot))
ANN2(1) static Symbol mksymbol(MemPool p, const m_str name, const Symbol next) {
  const Symbol s = mp_malloc2(p, sizeof(struct Symbol_));
  s->name = mstrdup(p, name);
  s->next = next;
  return s;
}

__attribute__((hot))
ANN Symbol insert_symbol(SymTable* ht, const m_str name) {
  const uint index = hash(name) % ht->sz;
  const Symbol syms = ht->sym[index];
  Symbol *const addr = &ht->sym[index];
  LOOP_OPTIM
  for(Symbol sym = syms; sym; sym = sym->next)
    if(!strcmp(sym->name, name))
      return sym;
  MUTEX_LOCK(ht->mutex);
  *addr = mksymbol(ht->p, name, syms);
  MUTEX_UNLOCK(ht->mutex);
  return ht->sym[index];
}
