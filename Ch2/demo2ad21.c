#include <stdio.h>
#define LEN 12

void invertedBits(int a, int k) {
  while (a > 0 || k > 0) {
    printf("%d", a % 2);
    a = a >> 1;
    k--;
  }
  printf("\n");
}

int main() {
  short int s, t;
  s = 123 << 1;
  t = 30 << 2;
  s++;
  t += 4;
  printf("AND\n");
  invertedBits(s, LEN);
  invertedBits(t, LEN);
  invertedBits(s & t, LEN);
  printf("OR\n");
  invertedBits(s, LEN);
  invertedBits(t, LEN);
  invertedBits(s | t, LEN);
  printf("XOR\n");
  invertedBits(s, LEN);
  invertedBits(t, LEN);
  invertedBits(s ^ t, LEN);  
  return 0;
}
