#include <stdio.h> // para getchar y putchar y EOF

int main() {
  int c;
  while ((c = getchar()) != EOF) { // asigna y checa directo
    putchar(c);
  }
  return 1;
}
