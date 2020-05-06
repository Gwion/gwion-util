#include <stdlib.h>
#include <string.h>
#include <defs.h>

char *strdup(const char *s) {
    char *p = xmalloc(strlen(s) + 1);
    if(p)
      strcpy(p, s);
    return p;
}

char *strndup(const char *s, size_t n) {
  char* c = xmalloc(n+1);
  if(c) {
    strncpy(c, s, n);
    c[n] = '\0';
  }
  return c;
}

char* strsep(char **stringp, const char *delim) {
  char *start = *stringp;
  char *ptr;

  if(!start)
    return NULL;
  if(!*delim)
    ptr = start + strlen(start);
  else {
    ptr = strpbrk(start, delim);
    if(!ptr) {
      *stringp = NULL;
      return start;
    }
  }
  *ptr = '\0';
  *stringp = ptr + 1;
  return start;
}
