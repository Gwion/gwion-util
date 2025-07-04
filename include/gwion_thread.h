/** @file: gwion_thread.h
\brief cross-platform thread functions
*/
#pragma once
#ifdef BUILD_ON_WINDOWS
#include <windows.h>
#define THREAD_RETTYPE long unsigned int
#define THREAD_FUNC(a) THREAD_RETTYPE(a)(void *data)
#define THREAD_TYPE    HANDLE
#define THREAD_CREATE(thread, func, arg)                                       \
  thread = CreateThread(NULL, 0, func, arg, 0, NULL)
#define THREAD_JOIN(thread) WaitForSingleObject(thread, 0)
#define THREAD_RETURN(arg)  return 0;
#define THREAD_DETACH(arg)

#define MUTEX_TYPE        HANDLE
#define MUTEX_INITIALIZER NULL
#define MUTEX_SETUP(x)    (x) = CreateMutex(NULL, FALSE, NULL)
#define MUTEX_CLEANUP(x)  CloseHandle(x)
#define MUTEX_LOCK(x)     emulate_pthread_mutex_lock(&(x))
#define MUTEX_COND_LOCK(x)
//#define MUTEX_UNLOCK(x)        (ReleaseMutex((x)) == 0)
#define MUTEX_UNLOCK(x)      ReleaseMutex((x))
#define MUTEX_COND_UNLOCK(x) (void)x
int emulate_pthread_mutex_lock(volatile MUTEX_TYPE *mx);

#define THREAD_COND_TYPE           HANDLE
#define THREAD_COND_SETUP(x)       x = CreateEvent(NULL, FALSE, FALSE, NULL);
#define THREAD_COND_WAIT(x, mutex) WaitForSingleObject(x, INFINITE)
#define THREAD_COND_SIGNAL(x)      SetEvent(x);
#define THREAD_COND_BROADCAST(x)      SetEvent(x);
#define THREAD_COND_CLEANUP(x)     CloseHandle(x)
#else
#include <pthread.h>

#define THREAD_RETTYPE void *
#define THREAD_FUNC(a) THREAD_RETTYPE(a)(void *data)
#define THREAD_TYPE    pthread_t
#define THREAD_CREATE(thread, func, arg)                                       \
  pthread_create(&thread, NULL, func, arg)
#define THREAD_JOIN(thread) pthread_join(thread, NULL)
#define THREAD_RETURN(arg)                                                     \
  {                                                                            \
    pthread_exit(NULL);                                                        \
    return NULL;                                                               \
  }
#define THREAD_DETACH(arg) pthread_detach(arg)

#define MUTEX_TYPE        pthread_mutex_t *
#define MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#define MUTEX_SETUP(x)                                                         \
  {                                                                            \
    pthread_mutexattr_t attr;                                                  \
    pthread_mutexattr_init(&attr);                                             \
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);                 \
    x = (pthread_mutex_t *)xmalloc(sizeof(pthread_mutex_t));                   \
    pthread_mutex_init(x, &attr);                                              \
  }
#define MUTEX_CLEANUP(x)                                                       \
  {                                                                            \
    pthread_mutex_destroy((x));                                                \
    xfree(x);                                                                  \
  }
#define MUTEX_LOCK(x)        pthread_mutex_lock((x))
#define MUTEX_COND_LOCK(x)   pthread_mutex_lock((x))
#define MUTEX_UNLOCK(x)      pthread_mutex_unlock((x))
#define MUTEX_COND_UNLOCK(x) pthread_mutex_unlock((x))

#define THREAD_COND_TYPE pthread_cond_t*
#define THREAD_COND_SETUP(x)                                                   \
  {                                                                            \
    x = (pthread_cond_t *)xcalloc(1, sizeof(pthread_cond_t));                  \
    pthread_cond_init(x, NULL);                                                \
  }
#define THREAD_COND_WAIT(x, mutex) pthread_cond_wait(x, mutex)
#define THREAD_COND_SIGNAL(x)      pthread_cond_signal(x)
#define THREAD_COND_BROADCAST(x)      pthread_cond_broadcast(x)
#define THREAD_COND_CLEANUP(x)                                                 \
  {                                                                            \
    pthread_cond_destroy(x);                                                   \
    xfree(x);                                                                  \
  }

#endif

#define STR_EXPAND(tok) #tok
#define STR(tok)        STR_EXPAND(tok)
#ifndef BUILD_ON_WINDOWS
#include <dlfcn.h>
#define DLOPEN(dl, b)   dlopen(dl, b)
#define DLSYM(dl, t, a) (t)(intptr_t) dlsym(dl, a)
#define DLCLOSE(dl)     dlclose(dl)
#define DLERROR()       dlerror()
#else
#include "windows.h"
#define DLOPEN(dl, b)   LoadLibrary(dl)
#define DLSYM(dl, t, a) (t)(intptr_t) GetProcAddress(dl, a)
#define DLCLOSE(dl)     FreeLibrary(dl)
#define DLERROR()       "plugin"
#endif
