#include <stdio.h>

int main() {
  int f = 1, x, n = 5;

  x = 1;
  while (x <= n) {
    f *= x; // multiply f by x
    x++;
  }
  printf("%d! = %d\n", n, f);

  return 0;
}
