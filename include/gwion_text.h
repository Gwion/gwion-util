#ifndef __GWTEXT
#define __GWTEXT
typedef struct GwText_ {
  m_str str;
  size_t cap;
  size_t len;
  MemPool mp;
} GwText;

ANN void text_add(GwText*, const m_str);
ANN static inline void text_release(GwText *text) {
  if(text->str) {
    mp_free2(text->mp, text->cap, text->str);
    text->str = NULL;
    text->cap = text->len = 0;
  }
}

// TODO: renaming
ANN static inline void text_reset(GwText *text) {
  if(text->str) {
    text->str = '\0';
    text->cap = text->len = 0;
  }
}

ANN static inline void free_mstr(MemPool mp, const m_str str) {
  _mp_free(mp, strlen(str) + 1, str);
}

ANN static inline m_str mstrdup(MemPool mp, const m_str name) {
  const m_str dup = (m_str)_mp_malloc(mp, strlen(name) + 1);
  strcpy(dup, name);
  return dup;
}
#endif
