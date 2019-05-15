#ifndef __TEXT
#define __TEXT
typedef struct GwText_ {
  m_str str;
  size_t cap;
  size_t len;
} GwText;

ANN void text_add(GwText*, const m_str);
ANN static inline void text_release(GwText *text) {
  if(text->str) {
    xfree(text->str);
    text->str = NULL;
    text->cap = text->len = 0;
  }
}
#endif
