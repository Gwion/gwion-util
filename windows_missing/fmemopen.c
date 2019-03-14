#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define min(a, b) (a > b ? b : a)

struct fmem {
    char *buf;
    size_t size;
    char *ops;
};

typedef struct fmem fmem_t;

static int readfn(void *, char *, int);
static int writefn(void *, const char *, int);
static fpos_t seekfn(void *, fpos_t, int);
static int closefn(void *);

FILE *fmemopen(void *buf, size_t size, const char *type) {
    fmem_t *fm = malloc(sizeof(*fm));
    memset(fm, 0, sizeof(*fm));
    fm->buf = buf;
    fm->size = size;
    fm->ops = buf;
    return funopen(fm, readfn, writefn, seekfn, closefn);
}

static int readfn(void *fm, char *buf, int size) {
    int min_size;
    fmem_t *fmem = (fmem_t *)fm;
    min_size = min(size, (int)(fmem->ops - fmem->buf));
    memcpy(buf, fmem->ops, min_size);
    fmem->ops += min_size;
    return min_size;
}

static int writefn(void *fm, const char *buf, int size) {
    int min_size;
    fmem_t *fmem = (fmem_t *)fm;
    min_size = min(size, (int)(fmem->size- (fmem->ops - fmem->buf)));
    memcpy(fmem->ops, buf, min_size);
    fmem->ops += min_size;
    return min_size;
}

static fpos_t seekfn(void *fm, fpos_t offset, int whence) {
  int status = 0;
  fmem_t *fmem = (fmem_t *)fm;
  switch (whence) {
    case SEEK_SET:
      fmem->ops = fmem->buf;
      fmem->ops += offset;
      break;
    case SEEK_END:
      fmem->ops = fmem->buf + fmem->size - 1;
      fmem->ops += offset;
      break;
    case SEEK_CUR:
      fmem->ops += offset;
    default:
      status = -1;
      break;
    }
    if(fmem->ops < fmem->buf || fmem->ops-fmem->buf > fmem->size) {
        fmem->ops = fmem->buf;
        status = -1;
    }
    return status;
}

static int closefn(void *fm) {
    free(fm);
    return 0;
}
