#include "gwion_util.h"

static inline size_t grow(size_t c) { return c * 2; }

ANN m_bit *hashmap_find(const HashMap hmap, m_bit *key, bool *ret) {
  HashMapValue *tombstone = NULL;
  const size_t  sz        = hashmap_value_size(hmap);
  for (size_t i = hmap->hash(key); i %= hmap->capacity; i++) {
    HashMapValue *const entry = hmap->data + i * sz;
    if (!entry->set) break;
    if (entry->deleted && !tombstone) {
      tombstone = entry;
      continue;
    }
    if (!hmap->eq(key, entry->data)) continue;
    if (tombstone) {
      memcpy(tombstone, entry, sz);
      entry->deleted = true;
    }
    *ret = true;
    return entry->data + hmap->key_size;
  }
  *ret = false;
  return NULL;
}

ANN static HashMapValue *find(const HashMap hmap, const m_bit *key) {
  const size_t sz = sizeof(HashMapValue) + hmap->key_size + hmap->val_size;
  for (size_t i = hmap->hash(key); i %= hmap->capacity; i++) {
    HashMapValue *const entry = hmap->data + i * sz;
    if (!entry->set) return entry;
  }
  return NULL;
}

ANN m_bit *hashmap_remove(const HashMap hmap, m_bit *key, bool *ret) {
  const size_t sz = hashmap_value_size(hmap);
  for (size_t i = hmap->hash(key); i %= hmap->capacity; i++) {
    HashMapValue *const entry = hmap->data + i * sz;
    if (!entry->set) break;
    if (!hmap->eq(key, entry->data)) continue;
    if (entry->deleted) break;
    entry->deleted = true;
    hmap->count--;
    *ret = true;
    return entry->data + hmap->key_size;
  }
  *ret = false;
  return NULL;
}

ANN static void adjust_capacity(HashMap hmap, const size_t capacity) {
  const size_t sz         = hashmap_value_size(hmap);
  const size_t old_cap    = hmap->capacity;
  hmap->capacity          = capacity;
  HashMapValue *const old = hmap->data;
  hmap->data              = mp_calloc2(hmap->mp, capacity * sz);
  hmap->count             = 0;
  for (size_t i = 0; i < old_cap; ++i) {
    HashMapValue *entry = old + i * sz;
    if (!entry->set || entry->deleted) continue;
    HashMapValue *dest = find(hmap, entry->data);
    memcpy(dest, entry, sz);
    hmap->count++;
  }
  mp_free2(hmap->mp, old_cap * sz, old);
}

ANN void hashmap_set(const HashMap hmap, m_bit *key, m_bit *val) {
  if (hmap->count + 1 > hmap->capacity * HMAP_MAX_LOAD) {
    const size_t capacity = grow(hmap->capacity);
    adjust_capacity(hmap, capacity);
  }
  const size_t sz = hashmap_value_size(hmap);
  for (size_t i = hmap->hash(key); i %= hmap->capacity; i++) {
    HashMapValue *const entry = hmap->data + i * sz;
    if (entry->set && !entry->deleted && hmap->eq(key, entry->data)) continue;
    memcpy(entry->data, key, hmap->key_size);
    memcpy(entry->data + hmap->key_size, val, hmap->val_size);
    entry->set     = true;
    entry->deleted = false;
    hmap->count++;
    return;
  }
}
