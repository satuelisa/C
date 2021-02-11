#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int nc, lc = 0, wc = 0, s = OUT;
  char c;
  for (nc = 0; (c = getchar()) != EOF; nc++) {
    if (c == '\n') {
      lc++;
    }
    if (c == ' ' || c == '\n' ||  c  == '\t') { // espacio
      s = OUT; // termina una palabra
    } else if (s == OUT) { // si no hay palabra activa
      s = IN; // ha comenzado una
      wc++; // la contamos
    }
  }
  printf("A total of %d characters forming %d words on %d lines.\n",  nc, wc, lc);
  return 1;
}
