#include <stdio.h>
#include "gwion_util.h"
#include "macro.h"
#include "parser.h"
#include "lexer.h"
#include "pp.h"

ANEW Scanner* new_scanner(const uint size) {
  Scanner* scan = (Scanner*)xcalloc(1, sizeof(Scanner));
  gwion_lex_init(&scan->scanner);
  gwion_set_extra(scan, scan->scanner);
  scan->jmp = (jmp_buf*)xcalloc(1, sizeof(jmp_buf));
  scan->pp = (PP*)xcalloc(1, sizeof(struct PP_));
  scan->pp->macros = (Hash)xcalloc(1, sizeof(struct Hash_));
  hini(scan->pp->macros, size);
  vector_init(&scan->pp->filename);
  return scan;
}

ANN void free_scanner(Scanner* scan) {
  vector_release(&scan->pp->filename);
  hend(scan->pp->macros);
  xfree(scan->pp->macros);
  xfree(scan->pp);
  xfree(scan->jmp);
  gwion_lex_destroy(scan->scanner);
  xfree(scan);
}

static inline void scanner_pre(Scanner* scan, const m_str filename, FILE* f) {
  scan->line = 1;
  scan->pos  = 1;
  scan->pp->def.idx = 0;
  scan->pp->npar = 0;
  vector_add(&scan->pp->filename, (vtype)NULL);
  vector_add(&scan->pp->filename, (vtype)filename);
  gwion_set_in(f, scan->scanner);
}

void scanner_post(Scanner* scan) {
  m_uint size = vector_size(&scan->pp->filename);
  while(size > 2)
    size = clear_buffer(&scan->pp->filename, scan, size > 6);
  scan->pp->entry = NULL;
  vector_clear(&scan->pp->filename);
  macro_del(scan->pp->macros);
}

Ast parse(Scanner* scan, const m_str filename, FILE* f) {
  scanner_pre(scan, filename, f);
  if(setjmp(*scan->jmp) || gwion_parse(scan))
    scan->ast = NULL;
  scanner_post(scan);
  return scan->ast;
}
