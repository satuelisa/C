#include <stdio.h>

int main() {
  int f = 1, x, n = 5;

  for (x = 1; x <= n; x++) {
    f *= x; // multiply f by x
  }
  printf("%d! = %d\n", n, f);

  return 0;
}
