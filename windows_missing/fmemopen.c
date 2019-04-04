#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

FILE *fmemopen(void *buf, size_t len, const char *type NUSED) {
	int fd;
	FILE *fp;
	char tp[MAX_PATH - 13];
	char fn[MAX_PATH + 1];
	HANDLE h;

	if(!GetTempPath(sizeof(tp), tp))
		return NULL;

	if(!GetTempFileName(tp, "confuse", 0, fn))
		return NULL;

	h = CreateFile(fn, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		       CREATE_ALWAYS, FILE_FLAG_DELETE_ON_CLOSE, NULL);
	if(INVALID_HANDLE_VALUE == h)
		return NULL;

	fd = _open_osfhandle((intptr_t)h, _O_APPEND);
	if (fd < 0) {
		CloseHandle(h);
		return NULL;
	}

	fp = fdopen(fd, "w+");
	if (!fp) {
		CloseHandle(h);
		return NULL;
	}
	fwrite(buf, len, 1, fp);
	rewind(fp);

	return fp;
}
