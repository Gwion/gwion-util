#include <string.h>
#include "defs.h"

static const m_str op_str[] = {
  "+", "-", "*", "/", "%",
  "&&", "||",  "==", "!=", ">", ">=", "<", "<=",
  "<<", ">>", "|", "&", "^",
  "++", "--", "!", "~", "new", "spork", "fork",
  "+=>", "-=>", "*=>", "/=>", "%=>",
  "<<=>", ">>=>", "&=>", "|=>", "^=>",
  "=>", "=<", "@=>", "@=<", "]=>", "]=<", "::", "$", "implicit",
  NULL
};

ANN int name2op(const m_str name) {
  int i = 0;
  while(op_str[i]) {
    if(!strcmp(name, op_str[i]))
      return i;
    ++i;
  }
  return GW_ERROR;
}

ANN m_str op2str(const Operator op) {
  if(op >= (sizeof(op_str) / sizeof(char*)))
    return NULL;
  return op_str[op];
}
