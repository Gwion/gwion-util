#ifndef __WINDOWS_MISSING
#include <stddef.h>
typedef unsigned int uint;
char *strdup(const char *s);
char *strndup(const char *s, size_t n);
int getline(char **lineptr, size_t *n, FILE *fp);
#endif
