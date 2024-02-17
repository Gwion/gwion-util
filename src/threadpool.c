#include "gwion_util.h"

typedef struct {
  void (*fun)(void *);
  void *arg;
} task_t;

struct threadpool_t {
  gwtlock_t    lock;
  gwtcond_t    cond;
  gwtthread_t *threads;
  task_t      *queue;
  uint32_t     head;
  uint32_t     tail;
  uint32_t     active;
  uint32_t     queue_size;
  uint32_t     started;
  bool         shutdown;
  bool         has_lock;
  bool         has_cond;
};

ANN static gwtreturn_t threadpool_thread(void *data) {
  threadpool_t *p = (threadpool_t *)data;
  while(true) {
    (void)gwt_lock(&p->lock);
    while(!p->active && !p->shutdown)
      (void)gwt_wait(&p->cond, &p->lock);
    if(p->shutdown) break;
    task_t task = p->queue[p->head];
    p->head = (p->head + 1) % p->queue_size;
    p->active--;
    (void)gwt_unlock(&p->lock);
    task.fun(task.arg);
  }
  (void)gwt_unlock(&p->lock);
  THREAD_RETURN(NULL);
}

ANN static bool alloc(threadpool_t *p, const uint32_t thread_count,
    const uint32_t queue_size) {
  return !(p->threads = malloc(thread_count * sizeof(gwtthread_t))) ||
         !(p->queue = malloc(queue_size * sizeof(task_t)));
}

ANN static bool utils(threadpool_t *p) {
#ifdef BUILD_ON_WINDOWS
  p->lock = NULL;
#endif
  if(gwt_lock_ini(&p->lock)) return false;
  p->has_lock = true;
  if(gwt_cond_ini(&p->cond)) return false;
  p->has_cond = true;
  return true;
}

ANN static bool start(threadpool_t *p, const uint32_t thread_count) {
  for(uint32_t i = 0; i < thread_count; i++) {
    const int ret = gwt_create(&p->threads[i], threadpool_thread, p);
    if(ret) return false;
    p->started++;
  }
  return true;
}

threadpool_t *new_threadpool(const uint32_t thread_count, const uint32_t queue_size) {
  threadpool_t *p = malloc(sizeof(threadpool_t));
  if(!p) return NULL;
  p->head = p->tail = p->active = 0;
  p->shutdown = p->has_lock = p->has_cond = false;
  p->started = 0;
  p->queue_size = queue_size;
  if(alloc(p, thread_count, queue_size) || !utils(p) ||
     !start(p, thread_count)) {
    free_threadpool(p);
    return NULL;
  }
  return p;
}

ANN2(1, 2) static bool add(threadpool_t *p, void (*fun)(void *), void *arg) {
  if(unlikely(p->shutdown || p->active == p->queue_size))
   return false;
  const uint32_t next = (p->tail + 1) % p->queue_size;
  task_t t = { .fun = fun, .arg = arg };
  p->queue[p->tail] = t;
  p->tail = next;
  p->active++;
  (void)gwt_signal(&p->cond);
  return true;
}

bool threadpool_add(threadpool_t *p, void (*fun)(void *), void *arg) {
  (void)gwt_lock(&p->lock);
  const bool ret = add(p, fun, arg);
  (void)gwt_unlock(&p->lock);
  return ret;
}

ANN void free_threadpool(threadpool_t *p) {
  (void)gwt_lock(&p->lock);
  p->shutdown = true;
  gwt_broadcast(&p->cond);
  (void)gwt_unlock(&p->lock);
  if(p->threads) {
    for(uint32_t i = 0; i < p->started; i++)
      gwt_join(p->threads[i]);
    free(p->threads);
  }
  if(p->queue) free(p->queue);
  if(p->has_lock) gwt_lock_end(&p->lock);
  if(p->has_cond) gwt_cond_end(&p->cond);
}
