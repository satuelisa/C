#include <stdio.h>
#define COLS 4

int main(int n, char** a)  {
  int i;
  char c;
  for (i = 1; i < n; i++) {
    c = (((i - 1) % COLS == COLS - 1) || (i == n - 1)) ? '\n' : '\t';
    printf("%s%c", a[i], c);
  }
  return 0;
}
