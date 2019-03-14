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
