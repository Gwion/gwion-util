#include "gwion_util.h"

ANN static inline Map scope_back(const Scope s) {
  return (Map)&VPTR((Vector)s, VLEN(s) - 1);
}

ANN vtype scope_lookup0(const Scope s, const vtype xid) {
  const Map   map = scope_back(s);
  const vtype ret = map_get(map, xid);
  if (!ret && VLEN(s) == 1) return map_get(&s->map, (vtype)xid);
  return ret;
}

ANN vtype scope_lookup1(const Scope s, const vtype xid) {
  for (m_uint i = VLEN(s) + 1; --i;) {
    const Map   map = (Map)&VPTR(s, i - 1);
    const vtype ret = map_get(map, xid);
    if (ret) return ret;
  }
  return map_get(&s->map, (vtype)xid);
}

ANN vtype scope_lookup2(const Scope s, const vtype xid) {
  const Map map = (Map)&VPTR(s, 0);
  return map_get(map, xid) ?: map_get(&s->map, (vtype)xid);
}

ANN void scope_add(const Scope s, const vtype xid, const vtype value) {
  if (VLEN(s) > 1)
    map_set(scope_back(s), xid, value);
  else
    map_set(&s->map, xid, value);
}

ANN void scope_commit(const Scope s) {
  map_commit((Map)&VPTR(s, 0), &s->map);
  map_clear(&s->map);
}

ANN void scope_init(MemPool p, Scope a) {
  vector_init((Vector)&a->map);
  vector_init((Vector)a);
  scope_push(p, a);
}

ANN Scope new_scope(MemPool p) {
  Scope a = mp_calloc(p, Scope);
  scope_init(p, a);
  return a;
}

ANN void scope_release(Scope a) {
  map_release((Map)&VPTR(a, 0));
  vector_release((Vector)a);
  vector_release((Vector)&a->map);
}

ANN void free_scope(MemPool p, Scope a) {
  scope_release(a);
  mp_free(p, Scope, a);
}

ANN m_bool scope_iter(struct scope_iter *iter, void *ret) {
  m_uint       size  = map_size(&iter->s->map);
  const m_uint vsize = vector_size((Vector)iter->s);
  const m_uint vec   = vsize - iter->vec;
  Map          map   = &iter->s->map;
  if (vsize == iter->vec) {
    if (iter->idx == size) return GW_ERROR;
  } else {
    map  = (Map)&VPTR(iter->s, vec - 1);
    size = map_size(map);
    if (iter->idx == size) {
      ++iter->vec;
      iter->idx = 0;
      return scope_iter(iter, ret);
    }
  }
  *(vtype *)ret = map_at(map, size - ++iter->idx);
  return GW_OK;
}
