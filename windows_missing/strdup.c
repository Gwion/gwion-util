#include <stdlib.h>
#include <string.h>

char *strdup(const char *s) {
    char *p = malloc(strlen(s) + 1);
    if(p)
      strcpy(p, s);
    return p;
}
