#include <stdio.h> // para printf

int main() {
  int f, c, l, u, s;
  l = 0;
  u = 300;
  s = 20;
  f = l;
  while (f <= u) {
    c = 5 * (f - 32) / 9;
    printf("%dF\t=\t%dC\n", f, c);
    f += s;
  }
  return 0;
}
