#ifndef __VECTOR
#define __VECTOR

typedef uintptr_t vtype;
typedef struct Vector_ * Vector;
#include "map_private.h"

ANEW ANN extern Vector new_vector(MemPool p);
ANN extern void   vector_init(const Vector);
ANN extern Vector vector_copy(MemPool p, const Vector);
ANN extern void   vector_copy2(const __restrict__ Vector, __restrict__ Vector);
ANN extern m_int  vector_find(const Vector, const vtype);

ANN static inline void vector_set(const Vector v, const vtype i, const vtype arg) {
  VPTR(v, i) = arg;
}
ANN static inline vtype vector_front(const Vector v) {
  return VPTR(v, 0);
}
ANN static inline vtype vector_at(const Vector v, const vtype i) {
  return VPTR(v, i);
}
ANN static inline vtype vector_back(const Vector v) {
  return VPTR(v, VLEN(v) - 1);
}
ANN static inline vtype vector_size(Vector const v) {
  return VLEN(v);
}

extern ANN void  vector_add(const Vector, const vtype);
extern ANN void  vector_rem(const Vector, const vtype);
extern ANN void  vector_rem2(const Vector, const vtype);
extern ANN vtype vector_pop(const Vector);
extern ANN void  vector_clear(const Vector);
extern ANN void  free_vector(MemPool p, const Vector);
extern ANN void  vector_release(const Vector);

ANN static inline void vector_realloc(const Vector v) {
  if((OFFSET + (VLEN(v) << 1) + 1) > VCAP(v))
    v->ptr = (m_uint*)xrealloc(v->ptr, (VCAP(v) <<= 1) * SZ_INT);
}
#endif
