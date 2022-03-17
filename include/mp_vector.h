#ifndef __MP_VECTOR
#define __MP_VECTOR

typedef struct MP_Vector {
  uint32_t len;
  uint32_t cap;
  uint8_t  ptr[];
} MP_Vector;

ANN static inline void mp_vector_resize(const MemPool mp, MP_Vector **ap, const uint32_t size, const uint32_t cap) {
  MP_Vector *a = *ap;
  *ap      = (MP_Vector *)mp_realloc(mp, a, sizeof(MP_Vector) + a->cap * size, sizeof(MP_Vector) + cap * size);
  (*ap)->cap = cap;
}

ANN MP_Vector *new_mp_vector(const MemPool mp, const uint32_t size, const uint32_t len);

ANN static inline void free_mp_vector(const MemPool mp, const uint32_t size, MP_Vector *a) {
  mp_free2(mp, sizeof(MP_Vector) + a->cap * size, a);
}

#define mp_vector_add(mp, a, type, data)                         \
  if (++((*a))->len >= ((*a))->cap)                              \
    mp_vector_resize(mp, (a), sizeof(type), (*(a))->cap * 2);    \
  *(type*)((*(a))->ptr + ((*a)->len - 1) * sizeof(type)) = data; \

#define mp_vector_at(a, type, index)                             \
  ((type*)(a->ptr + index * sizeof(type)))

#define mp_vector_set(a, type, index, data)                       \
  *(type*)(a->ptr + index * sizeof(type)) = (data)

#endif
