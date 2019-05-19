#include <stdlib.h>
#include <string.h>
#include "gwion_util.h"
#include "mpool_private.h"

ANN static void mp_set(struct pool* p, const uint32_t obj_sz) {
  p->obj_sz = round2szint(obj_sz);
  p->obj_id = BLK - 1;
  p->blk_id = -1;
  p->nblk   = 1;
  p->next   = NULL;
  p->data   = (uint8_t**)xcalloc(1, sizeof(uint8_t*));
}

MemPool mempool_ini(size_t sz) {
  MemPool p = (MemPool)xmalloc(sizeof(struct MemPool_));
  p->master_pool = new_pool(sz);
  p->pools = (struct pool**)xcalloc(p->sz = sz, sizeof(struct pool));
  MUTEX_SETUP(p->mutex);
  return p;
}

void mempool_end(MemPool mp) {
  LOOP_OPTIM
  for(m_uint i = mp->sz + 1; --i;) {
    struct pool* p = mp->pools[i - 1];
    if(p)
      mp_end(p);
  }
  mp_end(mp->master_pool);
  xfree(mp->master_pool);
  xfree(mp->pools);
  MUTEX_CLEANUP(mp->mutex);
  xfree(mp);
}

static struct pool* mp_create(MemPool mp, const uint32_t obj_sz, const uint32_t idx) {
  struct pool* p = (struct pool*)_mp_calloc2(mp->master_pool, 0);
  mp_set(p, obj_sz);
  mp->pools[idx] = p;
  return p;
}

ANN static struct pool* mp_get(MemPool mp, const uint32_t obj_sz) {
  if(obj_sz > (mp->sz+1)*SZ_INT)
    return NULL;
  const uint32_t idx = (obj_sz/SZ_INT) -1;
  return mp->pools[idx] ?: mp_create(mp, obj_sz, idx);
}

struct pool* mp_ini(MemPool mp, const uint32_t obj_sz) {
  return mp_get(mp, round2szint(obj_sz));
}

void mp_end(struct pool *p) {
  for(uint32_t i = 0; i < p->nblk && p->data[i]; ++i)
    xfree(p->data[i]);
  xfree(p->data);
}

static void _realloc(struct pool* p) {
  p->obj_id = 0;
  if(++p->blk_id == (int32_t)p->nblk) {
    p->nblk <<= 1;
    p->data = (uint8_t**)xrealloc(p->data, sizeof(uint8_t*)* p->nblk);
    for(uint32_t i = (p->nblk >> 1) + 1; i < p->nblk; ++i)
      p->data[i] = NULL;
  }
  p->data[p->blk_id] = (uint8_t*)xcalloc(BLK, p->obj_sz);
}

void *_mp_calloc2(struct pool *p, const m_bool zero) {
  if(p->next) {
    struct Recycle* recycle = p->next;
    p->next = p->next->next;
    if(zero)
      memset(recycle, 0, p->obj_sz);
    return recycle;
  }
  if(++p->obj_id == BLK)
    _realloc(p);
  return p->data[p->blk_id] + p->obj_id * p->obj_sz;
}

void _mp_free2(struct pool *p, void *ptr) {
  struct Recycle* next = p->next;
#ifdef POOL_CHECK
  memset(ptr, 0, p->obj_sz);
#endif
  p->next = ptr;
  p->next->next = next;
}

void _mp_free(MemPool mp, const m_uint size, void *ptr) {
  struct pool* p = mp_get(mp, round2szint(size));
  if(p) {
    MUTEX_LOCK(mp->mutex);
    _mp_free2(p, ptr);
    MUTEX_UNLOCK(mp->mutex);
  } else
    xfree(ptr);
}

struct pool* new_pool(const uint32_t obj_sz) {
  struct pool* p = (struct pool*)xmalloc(sizeof(struct pool));
  mp_set(p, obj_sz);
  return p;
}

void *_mp_calloc(MemPool mp, const m_uint size) {
  struct pool* p = mp_get(mp, round2szint(size));
  return p ? _mp_calloc2(p, 1) : (void*)xcalloc(1, size);
}

void *_mp_malloc(MemPool mp, const m_uint size) {
  struct pool* p = mp_get(mp, round2szint(size));
  return p ? _mp_calloc2(p, 0) : (void*)xmalloc(size);
}

void *mp_realloc(MemPool mp, void* ptr, const m_uint curr, const m_uint next) {
  const m_uint sz = round2szint(next);
  if(round2szint(curr) == sz)
    return ptr;
  void* ret = _mp_malloc(mp, sz);
  memcpy(ret, ptr, curr);
  mp_free2(mp, curr, ptr);
  return ret;
}

#ifndef MEM_UNSECURE
#include "err_msg.h" // for gwXalloc
static const void* xcheck(const void* a) {
  if(!a)
    exit(gw_err("Out of Memory"));
  return a;
}
#else
#define xcheck(a) (a)
#endif

ANEW const void* xmalloc(const m_uint sz) {
  const void* a = malloc(sz);
  return xcheck(a);
}

ANEW const void* xcalloc(const m_uint n, const m_uint sz) {
  void* a = calloc(n, sz);
  return xcheck(a);
}

ANEW const void* xrealloc(void* p, const m_uint sz) {
  void* a = realloc(p, sz);
  return xcheck(a);
}
