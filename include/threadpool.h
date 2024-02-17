#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#ifdef BUILD_ON_WINDOWS
typedef HANDLE              gwtthread_t;
typedef PCRITICAL_SECTION   gwtlock_t;
typedef PCONDITION_VARIABLE gwtcond_t;
typedef long unsigned       gwtreturn_t;
#else
#include <pthread.h>
typedef pthread_t       gwtthread_t;
typedef pthread_mutex_t gwtlock_t;
typedef pthread_cond_t  gwtcond_t;
typedef void*           gwtreturn_t;
#endif

typedef struct threadpool_t threadpool_t;

typedef enum {
  threadpool_lock_failure   = -2,
  threadpool_queue_full     = -3,
  threadpool_shutdown       = -4,
  threadpool_thread_failure = -5
} threadpool_error_t;

threadpool_t *new_threadpool(const uint32_t thread_count, const uint32_t queue_size);
ANN2(1, 2) bool threadpool_add(threadpool_t *pool, void (*routine)(void *), void *arg);
ANN void free_threadpool(threadpool_t *pool);


#ifdef BUILD_ON_WINDOWS
ANN static inline int gwt_lock(gwtlock_t *lock) {
  EnterCriticalSection(*lock);
  return 0;
}
ANN static inline int gwt_unlock(gwtlock_t *lock) {
  LeaveCriticalSection(*lock);
  return 0;
}
ANN static inline void gwt_wait(gwtcond_t *cond, gwtlock_t *lock) {
  SleepConditionVariableCS(*cond, *lock, INFINITE); // bool
}
ANN static inline int gwt_broadcast(gwtcond_t *cond) {
  WakeAllConditionVariable(*cond);
  return 0;
}
ANN static inline int gwt_signal(gwtcond_t *cond) {
  WakeConditionVariable(*cond);
  return 0;
}
ANN static inline int gwt_create(gwtthread_t *thread, gwtreturn_t (*fun)(void*), void *arg) {
  *thread = CreateThread(NULL, 0, fun, arg, 0, NULL);
  return !!*thread;
}
ANN static inline void gwt_join(gwtthread_t thread) {
  WaitForSingleObject(thread, INFINITE); // dword // (DWORD)0xFFFFFFFF on error
}
ANN static inline void gwt_lock_end(gwtlock_t *lock) {
  return DeleteCriticalSection(*lock);
}
ANN static inline int gwt_lock_ini(gwtlock_t *lock) {
  InitializeCriticalSection(*lock);
  return 0;
}
ANN static inline int gwt_cond_end(gwtcond_t *cond NUSED) { return 0;}
ANN static inline int gwt_cond_ini(gwtcond_t *cond) {
  InitializeConditionVariable(*cond);
  return 0;
}
#else
ANN static inline int gwt_lock(gwtlock_t *lock) {
  return pthread_mutex_lock(lock);
}
ANN static inline int gwt_unlock(gwtlock_t *lock) {
  return pthread_mutex_unlock(lock);
}
ANN static inline void gwt_join(gwtthread_t thread) {
  pthread_join(thread, NULL);
}
ANN static inline void gwt_wait(gwtcond_t *cond, gwtlock_t *lock) {
  pthread_cond_wait(cond, lock);
}
ANN static inline int gwt_broadcast(gwtcond_t *cond) {
  return pthread_cond_broadcast(cond);
}
ANN static inline int gwt_signal(gwtcond_t *cond) {
  return pthread_cond_signal(cond);
}
ANN static inline int gwt_lock_ini(gwtlock_t *lock) {
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  return pthread_mutex_init(lock, &attr);
}
ANN static inline void gwt_lock_end(gwtlock_t *lock) {
  pthread_mutex_destroy(lock); // int
}
ANN static inline int gwt_cond_ini(gwtcond_t *cond) {
  return pthread_cond_init(cond, NULL);
}
ANN static inline void gwt_cond_end(gwtcond_t *cond) {
  pthread_cond_destroy(cond); // int
}
ANN static inline bool gwt_create(gwtthread_t *thread, gwtreturn_t (*fun)(void*), void *arg) {
  return pthread_create(thread, NULL, fun, arg); // int
}
#endif


#endif
