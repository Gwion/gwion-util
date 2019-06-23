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
#endif
