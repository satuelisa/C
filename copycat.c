#include <stdio.h> // para getchar y putchar y EOF

int main() {
  int c;
  c = getchar(); // lee un caracter de entrada
  while (c != EOF) { // si no es terminacion de entrada
    putchar(c);
    c = getchar(); // lee otro
  }
  return 1;
}
