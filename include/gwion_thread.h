#ifndef __GWION_THREAD
#define __GWION_THREAD
#ifdef BUILD_ON_WINDOWS

#define THREAD_TYPE               HANDLE
#define THREAD_CREATE(thread, func, arg)  thread = CreateThread(NULL, 0, func, arg, 0, NULL);
#define THREAD_JOIN(thread)   WaitForSingleObject(thread, 0);
#define THREAD_RETURN(arg)        return arg;

#define MUTEX_TYPE             HANDLE
#define MUTEX_INITIALIZER      NULL
#define MUTEX_SETUP(x)         (x) = CreateMutex(NULL, FALSE, NULL)
#define MUTEX_CLEANUP(x)       CloseHandle(x)
#define MUTEX_LOCK(x)          emulate_pthread_mutex_lock((x))
#define MUTEX_UNLOCK(x)        ReleaseMutex((x))
int emulate_pthread_mutex_lock(volatile MUTEX_TYPE *mx);


#else
#include <pthread.h>

#define THREAD_TYPE               pthread_t
#define THREAD_CREATE(thread, func, arg)  pthread_create(&thread, NULL, func, arg);
#define THREAD_JOIN(thread)       pthread_join(thread, NULL);
#define THREAD_RETURN(arg)        pthread_exit(arg); return arg;

#define MUTEX_TYPE             pthread_mutex_t
#define MUTEX_INITIALIZER      PTHREAD_MUTEX_INITIALIZER
#define MUTEX_SETUP(x)
#define MUTEX_CLEANUP(x)       pthread_mutex_destroy((x))
#define MUTEX_LOCK(x)          pthread_mutex_lock((x))
#define MUTEX_UNLOCK(x)        pthread_mutex_unlock((x))

#endif
#endif