#include <stdio.h>

int main() {

  int x, a, b;
  a = 7;
  b = 15;

  x = a < b ? 3 : 4;
  printf("%d\n", x);
  
  if (a < b) {
    x = 3;
  } else {
    x = 4;
  }
  printf("%d\n", x);
  
  return 0;
}
