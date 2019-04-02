#ifndef __POOL
#define __POOL

typedef struct MemPool_* MemPool;

ANN struct pool* new_pool(const uint32_t elementSize);
ANN struct pool* mp_ini(MemPool p, const uint32_t elementSize);
ANN void mp_end(struct pool*);
ANEW ANN void *_mp_alloc2(struct pool*) __attribute__((hot));
ANEW ANN void *_mp_alloc(MemPool, const m_uint) __attribute__((hot));
ANN void _mp_free(MemPool, const m_uint, void*);
ANN void _mp_free2(struct pool*, void*);

#define mp_alloc(p, name) _mp_alloc(p, sizeof(struct name##_))
#define mp_free(p, name, a) _mp_free(p, sizeof(struct name##_), (a))
#define mp_free2(p, sz, a) _mp_free(p, sz, (a))
#define mp_alloc2(p, sz) _mp_alloc(p, sz)


struct MemPool_ {
  struct pool* master_pool;
  struct pool** pools;
  MUTEX_TYPE mutex;
  size_t sz;
};
MemPool mempool_ini(size_t sz);
void mempool_end(MemPool mp);
#endif
