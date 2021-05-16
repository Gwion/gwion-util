#include "gwion_util.h"

#define TABLE_SZ(sz) (sizeof(struct SymTable_) + sz * SZ_INT)

ANN SymTable* new_symbol_table(MemPool p, const size_t sz) {
  SymTable *const st = mp_malloc2(p, TABLE_SZ(sz));
  st->sz = sz;
  MUTEX_SETUP(st->mutex);
  st->p = p;
  return st;
}

ANN static void free_symbol(MemPool p, const Symbol s) {
  const Symbol next = s->next;
  mp_free2(p, sizeof(struct Symbol_*) + strlen(s->name) + 1, s);
  if(next)
    free_symbol(p, next);
}

ANN void free_symbols(SymTable *const ht) {
  LOOP_OPTIM
  for(uint i = ht->sz + 1; --i;) {
    const Symbol s = ht->sym[i - 1];
    if(s)
      free_symbol(ht->p, s);
  }
  MUTEX_CLEANUP(ht->mutex);
  mp_free2(ht->p, TABLE_SZ(ht->sz), ht);
}

#undef TABLE_SZ

ANN2(1,2) static inline Symbol mksymbol(MemPool p, const m_str name, const Symbol next) {
  const Symbol s = mp_malloc2(p, sizeof(struct Symbol_*) + strlen(name) + 1);
  s->next = next;
  strcpy(s->name, name);
  return s;
}

ANN Symbol insert_symbol(SymTable *const ht, const m_str name) {
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
