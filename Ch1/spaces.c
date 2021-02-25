#include <stdio.h>
#include <ctype.h>

int main () {
  int space = 0;
  char c;
  while ((c = getchar()) != EOF) {
    if (isspace(c)) {
      space = 1;
    } else {
      if (space)  {
	putchar('_');
	space = 0;
      }
      putchar(c);
    }
  }
  return 0;
}
