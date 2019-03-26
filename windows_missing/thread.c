#include <stdio.h>
#include <windows_missing.h>
#include <gwion_thread.h>

int emulate_pthread_mutex_lock(volatile MUTEX_TYPE *mx) {
  if (!*mx) {
    HANDLE p = CreateMutex(NULL, FALSE, NULL);
    if (InterlockedCompareExchangePointer((PVOID*)mx, (PVOID)p, NULL) != NULL)
      CloseHandle(p);
  }
  return WaitForSingleObject(*mx, INFINITE) == WAIT_FAILED;
}
