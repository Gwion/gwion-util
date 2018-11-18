#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defs.h"
#include "hash.h"
#include "mpool.h"

void hini(Hash h, const uint nmemb, const uint size) {
  h->table = (void*)xcalloc(((nmemb  + 3) & 0xfffffffc), size);
  h->size = size;
}

void hdel(const Hash h, void (*func)(void*)) {
  for(unsigned int i = h->size + 1; --i;) {
    void* s = h->table[i - 1];
    if(s) {
      func(s);
      h->table[i-1] = NULL;
    }
  }
}

void hend(const Hash h) {
  xfree(h->table);
}

unsigned int hash(const char *s0) {
  unsigned int h = 0;
  const unsigned char *s;
  for(s = (unsigned char*)s0; *s; ++s)
    h = h * 65599 + *s;
  return h;
}
