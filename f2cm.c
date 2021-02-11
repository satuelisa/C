#include <stdio.h> // para printf

int main() {
  float f, c; // ahora con decimales
  int l, u, s;
  l = 0;
  u = 300;
  s = 20;
  f = l;
  while (f <= u) {
    c = 5.0 * (f - 32) / 9.0;
    printf("%3.1fF\t=\t%6.2fC\n", f, c);
    f += s;
  }
  return 0;
}
