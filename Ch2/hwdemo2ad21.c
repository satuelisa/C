#include <stdio.h>

#define FALSE 0
#define TRUE 1

int prime(int n) { 
  int d;
  // the stupidest way possible so that you have something to improve upon  
  for (d = 2; d < n; d++) {
    if (n % d == 0) {
      return FALSE;
    }
  }
  return TRUE;  
}

int main() {
  int i;
  for (i = 1; i <= 30; i++) {
    printf("%d %ses primo\n", i, prime(i) ? "" : "no ");
  }
  return 0;
}
