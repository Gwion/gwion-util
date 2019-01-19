#include "gwion_test.h"
#include "gwion_util.h"

int main() {
  int count = 0, fail = 0;
  const uint start = count+1;
  EQ(1, 1, 1 == 1);
  NE(0, 1, 0 != 1);
}
