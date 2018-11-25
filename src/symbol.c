#include "stdlib.h"
#include "string.h"
#include "defs.h"
#include "symbol.h"
#include "mpool.h"
#ifdef TINY_MODE
#define SIZE 32653  /* should be prime */
#else
#define SIZE 65347  /* should be prime */
#endif

#define MAX_DISTANCE 2
#define min2(a, b) ((a) < (b) ? (a) : (b))
#define min(a, b, c) (min2(min2((a), (b)), (c)))

struct Symbol_ {
  m_str name;
  Symbol next;
};

static Symbol hashtable[SIZE];

ANN static void free_symbol(const Symbol s) {
  if(s->next)
    free_symbol(s->next);
  free(s->name);
  mp_free(Symbol, s);
}

void free_symbols(void) {
  LOOP_OPTIM
  for(uint i = SIZE + 1; --i;) {
    const Symbol s = hashtable[i - 1];
    if(s)
      free_symbol(s);
  }
}

__attribute__((hot,pure))
ANN static uint hash(const char *s0) {
  unsigned int h = 0;
  const unsigned char *s;
  for(s = (unsigned char*)s0; *s; ++s)
    h = h * 65599 + *s;
  return h;
}

__attribute__((hot))
ANN2(1) static Symbol mksymbol(const m_str name, const Symbol next) {
  const Symbol s = mp_alloc(Symbol);
  s->name = strdup(name);
  s->next = next;
  return s;
}

__attribute__((hot))
ANN Symbol insert_symbol(const m_str name) {
  const uint index = hash(name) % SIZE;
  const Symbol syms = hashtable[index];
  LOOP_OPTIM
  for(Symbol sym = syms; sym; sym = sym->next)
    if(!strcmp(sym->name, name))
      return sym;
   return hashtable[index] = mksymbol(name, syms);
}

m_str s_name(const Symbol s) { return s->name; }

static const char* wagner_fisher(const char *s, const char* t) {
  const size_t m = strlen(s);
  const size_t n = strlen(t);
  for(uint i = 0; i < m; ++i)
    d[i][0] = i;
  for(uint i = 0; i < n; ++i)
    d[0][i] = i;
  for(uint j = 1; j < n; ++j) {
    for(uint i = 1; i < m; ++i) {
      if(s[i] == t[j])
        d[i][j] = d[i-1][j-1];
      else
        d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + 1);
      if(d[i][j] > MAX_DISTANCE + 1)
        return NULL;
    }
  }
    return d[m-1][n-1] < MAX_DISTANCE? t : NULL;
}

ANN static const char* ressembles(const char* name) {
  const Symbol s = insert_symbol((char*)name);
  LOOP_OPTIM
  for(uint i = 0; i < SIZE; ++i) {
    const Symbol syms = hashtable[i];
    for(Symbol sym = syms; sym; sym = sym->next) {
      if(s == sym)
        continue;
      const char* ret = wagner_fisher(name, sym->name);
      if(ret)
        return ret;
    }
  }
  return NULL;
}

#include "err_msg.h"
ANN void did_you_mean(const char* name) {
  const char* s = ressembles(name);
  if(s)
    gw_err("\t(did you mean '%s'?)\n", s);
}
