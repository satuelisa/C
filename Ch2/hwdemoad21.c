#include <stdio.h>
#define LEN 12

void bits(int a, int k) {
  int i = k;
  int b[k];
  while (a > 0 || i > 0) {
    b[--i] = a % 2;
    a = a >> 1;
  }
  for (i = 0; i < k; i++) {
    printf("%d", b[i]);
  }
  printf("\n");
}

int main() {
  bits(10, LEN);
  bits(15, LEN);
  bits(35, LEN);  
  return 0;
}
