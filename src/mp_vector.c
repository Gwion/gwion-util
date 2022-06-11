#include "gwion_util.h"
#undef new_mp_vector
ANN MP_Vector *new_mp_vector(const MemPool mp, const uint32_t size, const uint32_t len) {
  m_uint cap   = 1;
  while (cap < len) cap *= 2;
  const size_t sz = cap * size;
  MP_Vector *a = (MP_Vector *)mp_malloc2(mp, sizeof(MP_Vector) + sz);
  a->cap  = cap;
  a->len  = len;
  return a;
}
