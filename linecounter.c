#include <stdio.h>

int main() {
  long nc;
  int lc;
  char c;
  for (nc = 0; (c = getchar()) != EOF; nc++) {
    if (c == '\n') {
      lc++;
    }
  }
  printf("A total of %ld characters on %d lines.\n",  nc, lc);
  return 1;
}
