#include "gwion_util.h"

ANN void map_clear(const Map v) {
  if (VCAP(v) != MAP_CAP)
    v->ptr = (m_uint *)xrealloc(v->ptr, (VCAP(v) = MAP_CAP) * SZ_INT);
  VLEN(v) = 0;
}

ANN inline void map_init(const Map a) {
  a->ptr  = (m_uint *)xcalloc(MAP_CAP, SZ_INT);
  VCAP(a) = MAP_CAP;
}

ANEW Map new_map(MemPool p) {
  const Map map = mp_calloc(p, Map);
  map_init(map);
  return map;
}

ANN vtype map_get(const Map map, const vtype key) {
  for (vtype i = VLEN(map) + 1; --i;)
    if (VKEY(map, i - 1) == key)
      return VVAL(map, i - 1);
  return 0;
}

ANN m_int map_index(const Map map, const vtype key) {
  for (vtype i = VLEN(map) + 1; --i;)
    if (VKEY(map, i - 1) == key)
      return i - 1;
  return -1;
}

ANN void map_set(const Map map, const vtype key, const vtype ptr) {
  for (vtype i = VLEN(map) + 1; --i;) {
    if (VKEY(map, i - 1) == key) {
      VVAL(map, i - 1) = ptr;
      return;
    }
  }
  vector_realloc((Vector)map);
  VKEY(map, VLEN(map))   = key;
  VVAL(map, VLEN(map)++) = ptr;
}

ANN void map_remove(const Map map, const vtype key) {
  const vtype len = VLEN(map);
  for (vtype i = 0, j = 0; i < len; ++i) {
    if (VKEY(map, i) != key) {
      VKEY(map, j) = VKEY(map, i);
      VVAL(map, j) = VVAL(map, i);
      ++j;
    } else
      --VLEN(map);
  }
}

ANN void map_commit(const restrict Map map, const restrict Map commit) {
  for (m_uint i = 0; i < map_size(commit); ++i)
    map_set(map, VKEY(commit, i), VVAL(commit, i));
}

ANN void map_release(const Map map) { xfree(map->ptr); }

ANN void free_map(MemPool p, const Map map) {
  map_release(map);
  mp_free(p, Map, map);
}
