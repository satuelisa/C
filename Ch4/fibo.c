#include <stdio.h>
/*

BASE CASE:
F(0) = 0
F(1) = 1
OTHERWISE n > 1
F(n) = F(n - 1) + F(n - 2)

*/

int dumbf(n) { // DUMB IDEA: redundant calculations
#ifdef DEBUG
  printf("Computing f(%d)\n", n);
#endif
  if (n > 1) {
    return dumbf(n - 1) + dumbf(n - 2);
  } else {
    return n;
  }
}

/*
  0 1 1 2 3 5 
 */
int f(n) { // SMART IDEA
  int front = 0, back = 1, i, temp;
  for (i = 2; i <= n; i++) {
    temp = front;
    front = back;
    back += temp;
  }
  return back;
}

int main() {
  int n =  15;
  printf("Element %d of the Fibonacci sequence is %d.\n", n, dumbf(n));
  printf("Element %d of the Fibonacci sequence is %d.\n", n, f(n));
  return 0;
}
