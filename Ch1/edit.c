#include <stdio.h>
#include <ctype.h> // toupper

int main() {
  char c;
  int skipping = 0; // not skipping, false is zero
  
  while ((c = getchar()) != '\n') {
    c = toupper(c);
    if (!skipping && c == '(') { // && AND (both must be true)
      skipping = 1; // one is true
    }
    if (skipping && c == ')') {
      skipping = 0; // stop skipping
    } else {
      if (!skipping) { // || OR (if any if met, do this stuff)
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
	  putchar('#');      
	} else {
	  putchar(c);
	}
      }
    }
  }
  printf("!!!\n");        
  return 0;
}
