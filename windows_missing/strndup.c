#include <stdlib.h>
#include <string.h>

char *strdup(const char *s) {
    char *p = malloc(strlen(s) + 1);
    if(p)
      strcpy(p, s);
    return p;
}

char *strndup(const char *s, size_t n) {
  char* c = malloc(n+1);
  if(c) {
    strncpy(c, s, n);
    c[n] = '\0';
  }
  return c;
}

char* strsep(char** stringp, const char* delim) {
  char* start = *stringp;
  char* p;

  if(!(p = (!start) ? strpbrk(start, delim) : NULL))
    *stringp = NULL;
  else {
    *p = '\0';
    *stringp = p + 1;
  }

  return start;
}
