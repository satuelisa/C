#include <stdio.h>

long int htoi(char s[]) {
  int i = 0;
  long int n = 0; // "a3d04"
  while (1) {
    if (s[i] >= '0' && s[i] <= '9') {
      n = 16 * n + (s[i] - '0');
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      n = 16 * n + (10 + (s[i] - 'a'));      
    } else {
      return n;
    }
    i++;
  }
}

int main(int c, char** s) {
  int i;
  for (i = 1; i < c; i++) {			
    printf("hex %s means dec %ld\n", s[i], htoi(s[i]));
  }
  return 1;
}
