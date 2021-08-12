#include <stdio.h>
#include <ctype.h>
#define ON 1
#define OFF 0

int main() {
  char c;
  int s, d = OFF, p, e; // digits or punctuation

  while ((c = getchar()) != EOF) {
    s = OFF;
    p = OFF;
    switch (c) {
    case ',':
    case '.':
    case '!':
    case '?':
      p = ON;
      break;
    case '(':
      e = ON;
      break;
    case ')':
      e = OFF;
      break;
    }
    if (!e && isdigit(c)) {
      d = ON;
    } else {
      if (d == ON) {
	putchar('X');
	s = ON;
      }
      d = OFF;
    }
    if (!p && !d && !s) {
      putchar(c);
    }
  }
  return 0;
}
