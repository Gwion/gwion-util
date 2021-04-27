#ifndef HASHMAP_H__
#define HASHMAP_H__

#define HMAP_MIN_CAP 16
#define HMAP_MAX_LOAD 0.75

typedef struct HashMapValue_ {
  bool set;
  bool deleted;
  m_bit data[];
} HashMapValue;

typedef struct HashMap_ {
  HashMapValue *data;
  bool   (*eq)(const m_bit*, const m_bit*);
  size_t (*hash)(const m_bit*);
  size_t key_size;
  size_t val_size;
  size_t capacity;
  size_t count;
  MemPool mp;
} *HashMap;

ANN static inline size_t hashmap_value_size(const HashMap a) {
  return sizeof(HashMapValue) + a->key_size + a->val_size;
}

ANN static inline void hashmap_init(HashMap a, MemPool p, const size_t key_size, const size_t val_size) {
  a->key_size = key_size;
  a->val_size = val_size;
  a->data = (HashMapValue*)mp_calloc2(p, HMAP_MIN_CAP * hashmap_value_size(a));
  a->capacity = HMAP_MIN_CAP;
  a->count = 0;
  a->mp = p;
}

ANN static inline HashMap new_hashmap(MemPool p, const size_t key_size, const size_t val_size) {
  const HashMap a = (HashMap)mp_malloc(p, HashMap);
  hashmap_init(a, p, key_size, val_size);
  return a;
}

ANN m_bit* hashmap_find(const HashMap hmap, m_bit* key, bool *ret);
ANN m_bit* hashmap_remove(const HashMap hmap, m_bit *key, bool *ret);
ANN void hashmap_set(const HashMap hmap, m_bit *key, m_bit *val);

ANN static inline void hashmap_release(HashMap a) {
  mp_free2(a->mp, a->capacity * hashmap_value_size(a), a->data);
}

ANN static inline void free_hashmap(HashMap a) {
  hashmap_release(a);
  mp_free(a->mp, HashMap, a);
}

#endif
