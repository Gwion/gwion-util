#include <string.h>
#include "gwion_util.h"
#include "gwion_test.h"

int main() {
  uint fail = 0, count = 0;
  const uint start = count + 1;

  Text text = {.str=NULL};

  text_add(&text, "first part.");
  NE(text.str, NULL, text is not null)
  EQ(strcmp(text.str, "first part."), 0, text.str)

  text_add(&text, "second part.");
  NE(text.str, NULL, text is not null)
  EQ(strcmp(text.str, "first part.second part."), 0, text.str)

  text_release(&text);
  EQ(text.str, NULL, text is now null)

  gw_out("%i..%i\n", start, count);
  return fail;
}
