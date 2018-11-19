#include "gwion_util.h"
#include "gwion_test.h"

int main() {
  uint fail = 0, count = 0;

  uint start = count + 1;
  Vector v = new_vector();
  NE(v, NULL, return a new vector);
  NE(v->ptr, NULL, with a pointer initialized);
  EQ(vector_size(v), 0, whoes size is zero);
  NO(vector_add(v, 12), add '12');
  EQ(vector_size(v), 1, size is now 1);
  EQ(vector_back(v), 12, and last elem is '12');
  NO(vector_pop(v), pop last element);
  NE(vector_back(v), 12, and last elem is not '12' anymore);
  NE(vector_back(v), VLEN(v), BEWARE: it is now vector length);
  NO(vector_add(v, 12), add '12');
  EQ(vector_at(v, 0), 12, by index);
  EQ(vector_find(v, 12), 0, by value);
  gw_out("%i..%i\n", start, count);
  return fail;
}
