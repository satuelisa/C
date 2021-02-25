#include <stdio.h>

int myatoi(char s[]) {
  int i, n = 0;

  for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
    n = 10 * n + (s[i] - '0'); // think about this well
  }
  return n;
}

int main(int c, char** s) {
  int i;
  for (i = 0; i < c; i++) {			
    printf("Twice %s is %d\n", s[i], 2 * myatoi(s[i]));
  }
  return 42;
}
