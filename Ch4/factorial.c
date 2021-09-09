#include <stdio.h>

// n! = 1 x 2 x 3 x 4 x ... x (n-1) x n

int fact(int n) {
#ifdef DEBUG
  printf("At %d now.\n", n);
#endif
  if (n < 3) {
    return n; // base case
  } else {
    return n * fact(n - 1);
  }
}

int ifact(n) {
  int i, result = 1;
  for (i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  int n = 8;
  printf("%d! = %d\n", n, fact(n));
  return 0;
}
