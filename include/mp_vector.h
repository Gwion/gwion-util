#ifndef __MP_VECTOR
#define __MP_VECTOR

typedef struct MP_Vector {
  uint32_t len;
  uint32_t cap;
  uint8_t  ptr[];
} MP_Vector;

ANN static inline void mp_vector_resize(const MemPool mp, MP_Vector **ap, const uint32_t size, const uint32_t cap) {
  MP_Vector *a = *ap;
  *ap      = (MP_Vector *)mp_realloc(mp, a, sizeof(MP_Vector) + (m_uint)(a->cap * size), sizeof(MP_Vector) + (m_uint)(cap * size));
  (*ap)->cap = cap;
}

ANN MP_Vector *new_mp_vector(const MemPool mp, const uint32_t size, const uint32_t len);

ANN static inline void free_mp_vector(const MemPool mp, const uint32_t size, MP_Vector *a) {
  mp_free2(mp, sizeof(MP_Vector) + (m_uint)(a->cap * size), a);
}

static inline uint32_t mp_vector_len(MP_Vector *a) {
  return a ? a->len : 0;
}

#define new_mp_vector(mp, type, data)                            \
  new_mp_vector(mp, sizeof(type), data)

#define free_mp_vector(mp, type, data)                           \
  free_mp_vector(mp, sizeof(type), data)

#define mp_vector_add(mp, a, type, data)                       {  \
  if (++((*a))->len >= ((*a))->cap)                               \
    mp_vector_resize(mp, (a), sizeof(type), (*(a))->cap * 2);     \
  *(type*)((*(a))->ptr + ((*a)->len - 1) * sizeof(type)) = data; }\

#define mp_vector_at(a, type, index)                             \
  ((type*)((a)->ptr + (index) * sizeof(type)))

#define mp_vector_set(a, type, index, data)                      \
  *(type*)((a)->ptr + (index) * sizeof(type)) = (data)

ANN static inline void mp_vector_rem(MP_Vector *const a, const uint32_t size, const uint32_t idx) {
  if (idx >= a->len) return;
  if (idx < a->len - 1)
    memmove(a->ptr + idx, a->ptr + idx + OFFSET + 1,
            (a->len - idx - 1) * size);
}

ANN static inline m_bit* mp_vector_pop(MP_Vector *const a, const uint32_t size) {
  m_bit *data = ((a)->ptr + (a->len-1) * size);
  a->len--;
  return data;
}

#define mp_vector_pop(a, type)                                 \
  ((type*)mp_vector_pop(a, sizeof(type)))

#define mp_vector_rem(a, type, idx)                            \
  mp_vector_rem(a, sizeof(type), idx)

#define mp_vector_rem2(a, type, data)                          \
  for(uint32_t i = 0; i < a->len; i++) {                       \
    if(data == mp_vector_at(a, type, i)) {                     \
      mp_vector_rem(a, type, i);                               \
      break;                                                   \
    }                                                          \
  }

#define mp_vector_back(a, type)                                \
  ((type*)((a)->ptr + (a->len-1) * sizeof(type)))

#endif
