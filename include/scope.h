/** @file: scope.h
\brief scope functions
*/
#pragma once

typedef struct Scope_ {
  vtype *     ptr;
  struct Map_ map;
} * Scope;

struct scope_iter {
  const Scope s;
  m_uint      vec;
  m_uint      idx;
};

extern ANN Scope       new_scope(MemPool);
extern ANN void        scope_init(MemPool, Scope);
extern ANEW ANN Vector scope_get(const Scope);
extern ANN vtype       scope_lookup0(const Scope, const vtype);
extern ANN vtype       scope_lookup1(const Scope, const vtype);
extern ANN vtype       scope_lookup2(const Scope, const vtype);
extern ANN void        scope_add(const Scope, const vtype, const vtype);
extern ANN void        scope_commit(const Scope);
extern ANN void        scope_release(Scope);
extern ANN void        free_scope(MemPool, Scope);
ANN static inline void scope_push(MemPool p NUSED, const Scope s) {
  vector_add((Vector)(void *)s, 0);
  map_init((Map)&VPTR(s, VLEN(s) - 1));
}

ANN static inline void scope_pop(MemPool p NUSED, const Scope s) {
  const m_uint back = vector_pop((Vector)(void *)s);
  map_release((Map)&back);
}

ANN static inline void _scope_init(const Scope s) {
  vector_init((Vector)(void *)s);
}
ANN bool scope_iter(struct scope_iter *iter, void *ret);
