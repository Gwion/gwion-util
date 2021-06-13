#include "gwion_util.h"

void hini(Hash h, const uint nmemb) {
  h->table = (void *)xcalloc(((nmemb + 3) & 0xfffffffc), sizeof(void *));
  h->size  = nmemb;
}

void hdel(const Hash h, void (*func)(MemPool, void *)) {
  for (unsigned int i = h->size + 1; --i;) {
    void *s = h->table[i - 1];
    if (s) {
      func(h->p, s);
      h->table[i - 1] = NULL;
    }
  }
}

void hend(const Hash h) { xfree(h->table); }

__attribute__((hot, pure)) unsigned int hash(const m_str s0) {
  unsigned int         h = 0;
  const unsigned char *s;
  for (s = (unsigned char *)s0; *s; ++s) h = h * 65599 + *s;
  return h;
}
