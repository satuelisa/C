#include <stdio.h>
#include <ctype.h> // toupper

int main() {
  char c;

  while ((c = getchar()) != '\n') {
    c = toupper(c);
    printf("We got a %c!\n", c);
    if (c == 'A') {
      printf(":)\n");      
    }
  }
  
  return 0;
}
