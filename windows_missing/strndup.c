#include <stdlib.h>
#include <string.h>

char *strndup(const char *s, size_t n) {
  char* c = malloc(n+1);
  if(c) {
    strncpy(c, s, n);
    c[n] = '\0';
  }
  return c;
}
