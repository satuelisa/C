#include <stdio.h>

int setbits(int x, int p, int n, int y) {
  int i, orig = x;
  int keep, mask = 0;
  for (i = 0; i < n; i++) {
    mask = (mask << 1) + 1;
  }
  keep = mask & y;
  x >>= (p + n);
  x <<= (p + n);
  x |= (keep << p);
  for (i = 0; i < p; i++) {
    mask = 1 << i;
    if ((orig & mask) > 0)  {
      x |= mask;
    }
  }
  return(x);
}

int main() {
  printf("%d\n", setbits(1234, 3, 4, 543));
}
