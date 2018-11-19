#ifndef __MAP
#define __MAP
typedef struct Map_    * Map;
ANEW extern Map new_map(void);
extern     void map_init(const Map);
extern ANN vtype map_get(const Map, const vtype);

ANN static inline vtype map_at(const Map map, const vtype index) {
  return VVAL(map, index);
}
extern ANN void map_set(const Map, const vtype, const vtype);
extern ANN void map_remove(const Map, const vtype);
extern ANN void map_commit(const __restrict__ Map, __restrict__ const Map);
extern ANN void map_clear(const Map);
extern ANN void free_map(const Map);
extern ANN void map_release(const Map);
ANN static inline vtype map_size(const Map map) {
  return VLEN(map);
}
#endif
