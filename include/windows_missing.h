#ifndef __WINDOWS_MISSING
#define __WINDOWS_MISSING
#include <windows.h>
#include <stddef.h>


// needed for clang
#ifndef PATH_MAX
#ifndef MAX_PATH
#define MAX_PATH 260
#endif
#define PATH_MAX MAX_PATH
#endif

typedef unsigned int uint;
char* strdup(const char *s);
char* strndup(const char *s, size_t n);
char* strsep(char** stringp, const char* delim);
int getline(char **lineptr, size_t *n, FILE *fp);
FILE *fmemopen(void *buf, size_t len, const char *type NUSED);
char *realpath(const char *path, char *resolved_path);
#endif
