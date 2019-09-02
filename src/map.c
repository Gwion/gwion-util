#include <stdlib.h>
#include <string.h>
#include "gwion_util.h"

ANN void map_clear(const Map v) {
  if(VCAP(v) != MAP_CAP)
    v->ptr = (m_uint*)xrealloc(v->ptr, (VCAP(v) = MAP_CAP) * SZ_INT);
  VLEN(v) = 0;
}

ANN inline void map_init(const Map a) {
  a->ptr = (m_uint*)xcalloc(MAP_CAP, SZ_INT);
  VCAP(a) = MAP_CAP;
}

ANEW Map new_map(MemPool p) {
  const Map map  = mp_calloc(p, Map);
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
  const vtype len = VLEN(map);
  for(vtype i = 0, j = 0; i < len; ++i) {
    if(VKEY(map, i) != key) {
      VKEY(map, j) = VKEY(map, i);
      VVAL(map, j) = VVAL(map, i);
      ++j;
    } else
      --VLEN(map);
  }
}

ANN void map_commit(const restrict Map map, const restrict Map commit) {
  map->ptr = (m_uint*)xrealloc(map->ptr, VCAP(commit) * SZ_INT);
  memcpy(map->ptr, commit->ptr, VCAP(commit) * SZ_INT);
}

ANN void map_release(const Map map) {
  xfree(map->ptr);
}

ANN void free_map(MemPool p, const Map map) {
  map_release(map);
  mp_free(p, Map, map);
}

