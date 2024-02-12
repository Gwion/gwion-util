/** @file: mpool.h
\brief memory pool
*/

#ifndef __POOL
#define __POOL

typedef struct MemPool_ {
  struct pool * master_pool;
  struct pool **pools;
  size_t *      sizes;
  size_t        sz;
} * MemPool;

ANN struct pool *new_pool(const uint32_t elementSize);
ANN struct pool *mp_ini(MemPool p, const uint32_t elementSize);
ANN void         mp_end(struct pool *);
ANEW ANN void *_mp_calloc2(struct pool *, const bool) __attribute__((hot));
ANEW ANN void *_mp_calloc(MemPool, const m_uint) __attribute__((hot));
ANEW ANN void *_mp_malloc(MemPool, const m_uint) __attribute__((hot));
ANN void       _mp_free(MemPool, const m_uint, void *);
ANN void       _mp_free2(struct pool *, void *);

void *mp_realloc(MemPool mp, void *ptr, const m_uint curr, const m_uint next);
#define mp_malloc(p, name)  _mp_malloc(p, sizeof(struct name##_))
#define mp_calloc(p, name)  _mp_calloc(p, sizeof(struct name##_))
#define mp_free(p, name, a) _mp_free(p, sizeof(struct name##_), (a))
#define mp_free2(p, sz, a)  _mp_free(p, sz, (a))
#define mp_calloc2(p, sz)   _mp_calloc(p, sz)
#define mp_malloc2(p, sz)   _mp_calloc(p, sz)

MemPool mempool_ini(const size_t sz);
void    mempool_end(MemPool mp);
#endif
