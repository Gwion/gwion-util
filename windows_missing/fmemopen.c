#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <defs.h>
#include <windows.h>

static HANDLE fmemopen_handle(void) {
  char tp[MAX_PATH - 13];
  char fn[MAX_PATH + 1];
  if(!GetTempPath(sizeof(tp), tp))
    return NULL;
  if(!GetTempFileName(tp, "confuse", 0, fn))
    return NULL;
  HANDLE h = CreateFile(fn, GENERIC_READ | GENERIC_WRITE, 0, NULL,
           CREATE_ALWAYS, FILE_FLAG_DELETE_ON_CLOSE, NULL);
  return h != INVALID_HANDLE_VALUE ? h : NULL;
}

FILE *fmemopen(void *buf, size_t len, const char *type NUSED) {
  int fd;
  FILE *fp;
  HANDLE h = fmemopen_handle();
  if((fd  = _open_osfhandle((intptr_t)h, _O_APPEND)) < 0 || !(fp = fopen(fd, "w+"))) {
    CloseHandle(h);
    return NULL;
  }
  fwrite(buf, len, 1, fp);
  rewind(fp);
  return fp;
}
