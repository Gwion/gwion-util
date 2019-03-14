#ifndef __WINDOWS_MISSING
#include <stddef.h>
typedef unsigned int uint;
char* strdup(const char *s);
char* strndup(const char *s, size_t n);
char* strsep(char** stringp, const char* delim);
int getline(char **lineptr, size_t *n, FILE *fp);
#endif
