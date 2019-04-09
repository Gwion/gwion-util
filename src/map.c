#include <stdlib.h>
#include <string.h>
#include "gwion_util.h"

ANN void map_clear(const Map v) {
  v->ptr = (m_uint*)xrealloc(v->ptr, (VCAP(v) = MAP_CAP) * SZ_INT);
  VLEN(v) = 0;
}

ANN inline void map_init(const Map a) {
  a->ptr = (m_uint*)xcalloc(MAP_CAP, SZ_INT);
  VCAP(a) = MAP_CAP;
}

ANEW Map new_map(MemPool p) {
  const Map map  = mp_alloc(p, Map);
  map_init(map);
  return map;
}

ANN vtype map_get(const Map map, const vtype key) {
  for(vtype i = VLEN(map) + 1; --i;)
    if(VKEY(map, i - 1) == key)
      return VVAL(map, i - 1);
  return 0;
}

ANN void map_set(const Map map, const vtype key, const vtype ptr) {
  for(vtype i = VLEN(map) + 1; --i;) {
    if(VKEY(map, i - 1) == key) {
      VVAL(map, i - 1) = ptr;
      return;
    }
  }
  vector_realloc((Vector)map);
  VKEY(map, VLEN(map)) = key;
  VVAL(map, VLEN(map)++) = ptr;
}

ANN void map_remove(const Map map, const vtype key) {
  struct Map_ tmp;
  map_init(&tmp);
  for(vtype i = 0; i < VLEN(map); ++i)
    if(VKEY(map, i) != key)
      map_set(&tmp, key, VVAL(map, i));
  xfree(map->ptr);
  map->ptr = tmp.ptr;
}

ANN void map_commit(const restrict Map map, const restrict Map commit) {
  map->ptr = realloc(map->ptr, VCAP(commit) * SZ_INT);
  memcpy(map->ptr, commit->ptr, VCAP(commit) * SZ_INT);
}

ANN void free_map(MemPool p, const Map map) {
  xfree(map->ptr);
  mp_free(p, Map, map);
}

ANN void map_release(const Map map) {
  xfree(map->ptr);
}
