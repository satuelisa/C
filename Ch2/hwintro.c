#include <math.h>
#include <stdio.h>

int main() {
  int n = 30, b, x;
  b = 2;
  x = 1 + (int)floor(log(n) / log(b));
  printf("%d base %d we need a five, %d\n", n, b, x);
  b = 5;
  x = 1 + (int)floor(log(n) / log(b));  
  printf("%d base %d we need a three, %d\n", n, b, x);
  b = 10;
  x = 1 + (int)floor(log(n) / log(b));  
  printf("%d base %d we need a two, %d\n", n, b, x);
  
  return 1;
}
