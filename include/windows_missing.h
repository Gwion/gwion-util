#ifndef __WINDOWS_MISSING
#include <stddef.h>
typedef unsigned int uint;
char *strndup(const char *s, size_t n);
int getline(char **lineptr, size_t *n, FILE *fp);
FILE *fmemopen(void *buf, size_t size, const char *type);
#endif
