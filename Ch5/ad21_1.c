#include <stdio.h>

int sum(int a, int b) {
  return a + b;
}

void make_double(int* a) {
  printf("first it is %d\n", *a);  
  *a *= 2; // modify the stored value
  printf("now it is %d\n", *a);
}

int main() {
  int x = 4;
  int y = 3;
  int* address = &y; // give me the address
  make_double(address); 
  printf("%d + %d = %d\n", x, y, sum(x, y));
  return 13;
}
