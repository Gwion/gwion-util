/** @file: carg.c
\brief simple argument utilities
**/
/** \dir \brief src the source dir */
#include "gwion_util.h"

ANN m_str option_argument(struct CArg *ca) {
  const char key = ca->argv[ca->idx][1];
  const m_str str = (ca->argv[ca->idx][2] == '\0' ? ca->argv[++ca->idx] : ca->argv[ca->idx] + 2);
  if(!str)
    gw_err(_("option '-%c' needs arguments\n"), key);
  return str;
}

/** used internally to split arguments **/
struct ArgSplitter {
  m_str str;
  Vector v;
  MemPool mp;
};

ANN static void _split_args(struct ArgSplitter *as) {
  const size_t sz = strlen(as->str);
  char buf[sz + 1], prev = '\0';
  m_uint i = 0, j = 0;
  char c;
  while((c = as->str[i]) != '\0') {
    const m_bool skip  = prev == '\\';
    const m_bool comma = c == ',';
    if(comma) {
      if(!skip)
        break;
      --j;
    }
    buf[j++] = (prev = c);
    ++i;
  }
  buf[i] = '\0';
  vector_add(as->v, (vtype)mstrdup(as->mp, buf));
  if(i == sz)
    return;
  as->str += i + 1;
  _split_args(as);
}

ANN Vector split_args(MemPool p, const m_str str) {
  struct ArgSplitter as = { .str=str, .v=new_vector(p), .mp=p };
  _split_args(&as);
  return as.v;
}
