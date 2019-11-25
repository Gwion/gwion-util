#ifndef __CARG
#define __CARG

struct CArg {
  char** argv;
  int argc;
  int idx;
};

ANN m_str option_argument(struct CArg *ca);

ANN Vector split_args(MemPool, const m_str str);
#endif
