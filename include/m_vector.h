#ifndef __M_VECTOR
#define __M_VECTOR

typedef struct M_Vector_  {
  m_bit* ptr;
} * M_Vector;
#define ARRAY_OFFSET SZ_INT * 4
#define ARRAY_PTR(array) (array->ptr + ARRAY_OFFSET)
#define ARRAY_LEN(array) *(m_uint*)(array->ptr)
#define ARRAY_SIZE(array) *(m_uint*)(array->ptr + SZ_INT)
#define ARRAY_CAP(array) *(m_uint*)(array->ptr + SZ_INT*2)
#define ARRAY_MIN(array) (ARRAY_SIZE(array) * 4 + ARRAY_OFFSET)

ANN static inline m_uint m_vector_size(const M_Vector v) {
  return ARRAY_LEN(v);
}

ANN static inline void m_vector_get(const M_Vector v, const m_uint i, void* c) {
  const m_uint size = ARRAY_SIZE(v);
  memcpy(c, ARRAY_PTR(v) + i * size, size);
}

ANN static inline m_bit* m_vector_addr(const M_Vector v, const m_uint i) {
  return &*(m_bit*)(ARRAY_PTR(v) + i * ARRAY_SIZE(v));
}

void m_vector_init(const M_Vector array,  const m_uint size, const m_uint len);

ANN static inline M_Vector new_m_vector(MemPool p, const m_uint size, const m_uint len) {
  const M_Vector array = mp_calloc(p, M_Vector);
  m_vector_init(array, size, len);
  return array;
}


ANN static inline void m_vector_release(M_Vector a) {
  xfree(a->ptr);
}

ANN static inline void free_m_vector(MemPool p, M_Vector a) {
  m_vector_release(a);
  mp_free(p, M_Vector, a);
}

ANN void m_vector_set(const M_Vector,  const m_uint, const void*);
ANN void m_vector_add(const M_Vector,  const void*);
ANN void m_vector_rem(const M_Vector,  const m_uint);
ANN void m_vector_insert(const M_Vector v, m_uint index, const void* data);
ANN void m_vector_add_front(const M_Vector v, const void* data);
#endif
