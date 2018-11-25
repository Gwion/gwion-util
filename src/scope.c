#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "vector.h"
#include "map.h"
#include "scope.h"

ANN static inline Map scope_back(const Scope s) {
  return (Map)vector_back((Vector)s);
}

ANN vtype scope_lookup0(const Scope s, const vtype xid) {
  const Map map = scope_back(s);
  const vtype ret = map_get(map, xid);
  if(!ret && VLEN(s) == 1)
    return map_get(&s->map, (vtype)xid);
  return ret;
}

ANN vtype scope_lookup1(const Scope s, const vtype xid) {
  for(m_uint i = VLEN(s) + 1; --i;) {
    const Map map = (Map)VPTR(s, i - 1);
    const vtype ret = map_get(map, xid);
    if(ret)
      return ret;
  }
  return map_get(&s->map, (vtype)xid);
}

ANN void scope_add(const Scope s, const vtype xid, const vtype value) {
  if(VLEN(s) > 1)
    map_set(scope_back(s), xid, value);
  else
    map_set(&s->map, xid, value);
}

ANN void scope_commit(const Scope s) {
  map_commit((Map)VPTR(s, 0), &s->map);
  map_clear(&s->map);
}

ANN void scope_init(Scope a) {
  vector_init((Vector)&a->map);
  vector_init((Vector)a);
  scope_push(a);
}

ANN void scope_release(Scope a) {
  free_map((Map)VPTR(a, 0));
  vector_release((Vector)a);
  vector_release((Vector)&a->map);
}

ANN Vector scope_get(const Scope s) {
  m_uint size = OFFSET + VLEN(&s->map);
  m_uint iter = 0;
  for(m_uint j = 0; j < VLEN(s); j++) {
    const Map map = (Map)VPTR(s, j);
    size += VLEN(map);
  }
  const Vector ret = new_vector();
  if(size > MAP_CAP)
    ret->ptr = (vtype*)xrealloc(ret->ptr, size * SZ_INT);

  for(m_uint j = 0; j < VLEN(s); j++) {
    const Map map = (Map)VPTR(s, j);
    for(m_uint i = 0; i < VLEN(map); i++)
      VPTR(ret, iter++) =  VVAL(map, i);
  }
  for(m_uint i = 0; i < VLEN(&s->map); i++)
      VPTR(ret, iter++) =  VVAL(&s->map, i);
  VCAP(ret) = size;
  VLEN(ret) = iter;
  return ret;
}
