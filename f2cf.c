#include <stdio.h> // para printf

int main() {
  float f;
  int l, u, s;
  l = 0;
  u = 300;
  s = 20;

  for (f = l; f <= u; f += s) { // con ciclo for sale compacto
    printf("%3.1fF\t=\t%6.2fC\n", f, 5.0 * (f - 32) / 9.0);
  }
  return 0;
}
