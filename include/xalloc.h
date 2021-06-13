#ifndef __ALLOC
#define __ALLOC
#ifndef MEM_UNSECURE
static void *xcheck(void *a) {
  if (a) return a;
  gw_err(_("Out of Memory\n"));
  THREAD_RETURN(NULL);
}
#else
#define xcheck(a) (a)
#endif

ANEW static inline void *xmalloc(const m_uint sz) {
  void *a = malloc(sz);
  return xcheck(a);
}

ANEW static inline void *xcalloc(const m_uint n, const m_uint sz) {
  void *a = calloc(n, sz);
  return xcheck(a);
}

ANEW static inline void *xrealloc(void *p, const m_uint sz) {
  void *a = realloc(p, sz);
  return xcheck(a);
}

#define xfree(a) free(a)
#endif
