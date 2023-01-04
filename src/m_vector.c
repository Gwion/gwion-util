#include "gwion_util.h"

ANN static inline void resize(const M_Vector v, const m_uint cap) {
  v->ptr       = (m_bit *)xrealloc(v->ptr, ARRAY_OFFSET + cap * ARRAY_SIZE(v));
  ARRAY_CAP(v) = cap;
}

void m_vector_init(const M_Vector array, const m_uint size, const m_uint len) {
  m_uint cap      = 2;
  while (cap < len) cap *= 2;
  const size_t sz = ARRAY_OFFSET + cap * size;
  array->ptr      = (m_bit *)xcalloc(1, sz);
  ARRAY_CAP(array)  = cap;
  ARRAY_SIZE(array) = size;
  ARRAY_LEN(array)  = len;
}

ANN void m_vector_add(const M_Vector v, const void *data) {
  const m_uint size = ARRAY_SIZE(v);
  if (++ARRAY_LEN(v) >= ARRAY_CAP(v)) resize(v, ARRAY_CAP(v) *= 2);
  memcpy(ARRAY_PTR(v) + (ARRAY_LEN(v) - 1) * size, data, size);
}

ANN void m_vector_add_front(const M_Vector v, const void *data) {
  const m_uint size = ARRAY_SIZE(v);
  if (++ARRAY_LEN(v) >= ARRAY_CAP(v)) resize(v, ARRAY_CAP(v) *= 2);
  memmove(ARRAY_PTR(v) + size, ARRAY_PTR(v), ARRAY_LEN(v) * size);
  memmove(ARRAY_PTR(v), data, size);
}

ANN void m_vector_set(const M_Vector v, const m_uint i, const void *data) {
  const m_uint size = ARRAY_SIZE(v);
  memcpy(ARRAY_PTR(v) + i * size, data, size);
}

ANN void m_vector_rem(const M_Vector v, m_uint index) {
  const m_uint size = ARRAY_SIZE(v);
  if (index < ARRAY_LEN(v) - 1)
    memmove(ARRAY_PTR(v) + index * size, ARRAY_PTR(v) + (index + 1) * size,
            (ARRAY_LEN(v) - index - 1) * size);
  --ARRAY_LEN(v);
  if (ARRAY_LEN(v) < ARRAY_CAP(v) / 2) resize(v, ARRAY_CAP(v) / 2);
}

ANN void m_vector_insert(const M_Vector v, m_uint index, const void *data) {
  const size_t size = ARRAY_SIZE(v);
  if (++ARRAY_LEN(v) >= ARRAY_CAP(v)) resize(v, ARRAY_CAP(v) *= 2);
  memmove(ARRAY_PTR(v) + (index + 1) * size, ARRAY_PTR(v) + index * size,
          (ARRAY_LEN(v) - index + 1) * size);
  memcpy(ARRAY_PTR(v) + index * size, data, size);
}
