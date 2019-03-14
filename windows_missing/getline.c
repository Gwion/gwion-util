#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#define GETLINE_MINSIZE 16
int getline(char **lineptr, size_t *n, FILE *fp) {
  int ch, i = 0;
  char free_on_err = 0, *p;

  errno = 0;
  if(!lineptr || !n || !fp) {
      errno = EINVAL;
      return -1;
  }
  if(!*lineptr) {
    *n = GETLINE_MINSIZE;
    *lineptr = (char *)malloc( sizeof(char) * (*n));
    if (*lineptr == NULL) {
        errno = ENOMEM;
        return -1;
    }
    free_on_err = 1;
  }
  for (i=0; ; i++) {
    ch = fgetc(fp);
    while (i >= (int)((*n) - 2)) {
      *n *= 2;
      if(!(p = realloc(*lineptr, sizeof(char) * (*n)))) {
        if (free_on_err)
          free(*lineptr);
        errno = ENOMEM;
        return -1;
      }
      *lineptr = p;
    }
    if(ch == EOF) {
      if(!i) {
        if(free_on_err)
          free(*lineptr);
        return -1;
      }
      (*lineptr)[i] = '\0';
      *n = i;
      return i;
    }
    if(ch == '\n') {
      (*lineptr)[i] = '\n';
      (*lineptr)[i+1] = '\0';
      *n = i+1;
      return i+1;
    }
    (*lineptr)[i] = (char)ch;
  }
}
