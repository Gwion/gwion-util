#ifndef __WINDOWS_MISSING
#include <stddef.h>
typedef unsigned int uint;
char* strdup(const char *s);
char* strndup(const char *s, size_t n);
char* strsep(char** stringp, const char* delim);
int getline(char **lineptr, size_t *n, FILE *fp);
FILE *fmemopen(void *buf, size_t len, const char *type __attribute__((unused)));
char *realpath(const char *path, char *resolved_path);
int scandir(const char *dirname, struct dirent ***namelist,
  int (*select)(struct dirent *),
  int (*dcomp)(const void *, const void *));
#endif
