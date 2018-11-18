#ifndef __MACRO
#define __MACRO
typedef struct Args_* Args;
typedef struct Macro_* Macro;

typedef struct GWPP_* GWPP;
struct pp_info {
  int data[32];
  int idx;
};

enum gwpp_state {
  NORMAL,
  AFTER_ARG, // paste after arg, e.g. do not print sharps (find when)
  QUOTED,
  COMMENT,
  MACRO, // we need a append_check inline function
};

enum tok_type {
  TOK_NONE,
  TOK_ESCAPE,
  TOK_SHARP,
  TOK_PASTE,
  TOK_QUOTE,
};

struct GWPP_ {
  FILE* out;
  char* filename;
  struct Hash_ h;
  struct pp_info* ifdef;
  struct pp_info* lines;
  enum tok_type tok;
  enum gwpp_state state;
  int err;
};//__attribute__((packed));

struct Args_ {
  char* name;
  char* text;
  Args next;
};
Args new_args(const char*);
void clean_args(const Args);
struct Macro_ {
  char* name;
  char* text;
  Args  base;
  Args  args;
  Macro next;
  uint line;
  uint pos;
};

void  macro_del(const Hash);
Macro macro_add(const Hash, const char*);
int   macro_rem(const Hash, const char*);
Macro macro_has(const Hash, const char*);
#endif
