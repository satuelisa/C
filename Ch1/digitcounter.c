#include <stdio.h>
#include <ctype.h>
#define IN 1
#define OUT 0

int main() {
  int i, j, w = 0, o = 0;
  int d[10];
  char c;

  for (i = 0; i < 10; i++) {
    d[i] = 0; // inicialmente en ceros
  }
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      d[c - '0'] += 1; // incremento
    } else if (isspace(c)) {
      w++;
    } else {
      ++o;
    }
  }
  for (i = 0; i < 10; i++) {
    printf("%d of %d\t", d[i], i);
    for (j = 0; j < d[i]; j++) {
      printf("#"); // Ex. 1-13
    }
    printf("\n");    
  }
  printf("%d spaces and %d other characters\n", w, o);
  return 1;
}
