#ifndef __WINDOWS_MISSING
#define __WINDOWS_MISSING
#include <windows.h>
#include <stddef.h>
typedef unsigned int uint;
char* strdup(const char *s);
char* strndup(const char *s, size_t n);
char* strsep(char** stringp, const char* delim);
int getline(char **lineptr, size_t *n, FILE *fp);
FILE *fmemopen(void *buf, size_t len, const char *type __attribute__((unused)));
char *realpath(const char *path, char *resolved_path);
/*
#define MUTEX_TYPE             HANDLE
#define MUTEX_INITIALIZER      NULL
#define MUTEX_SETUP(x)         (x) = CreateMutex(NULL, FALSE, NULL)
//#define MUTEX_CLEANUP(x)       (CloseHandle(x) == 0)
#define MUTEX_CLEANUP(x)       CloseHandle(x)
#define MUTEX_LOCK(x)          emulate_pthread_mutex_lock((x))
//#define MUTEX_UNLOCK(x)        (ReleaseMutex(x) == 0)
#define MUTEX_UNLOCK(x)        ReleaseMutex((x))
int emulate_pthread_mutex_lock(volatile MUTEX_TYPE *mx);

#define THREAD_TYPE               HANDLE
#define THREAD_CREATE(thread, func, arg)  thread = CreateThread(NULL, 0, func, arg, 0, NULL);
#define THREAD_JOIN(thread)   WaitForSingleObject(thread, 0);
#define THREAD_RETURN(arg)        return arg;
*/
#endif
