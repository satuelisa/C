#include <stdio.h>

int main() {
  char c = getchar();

  switch (c) {
  case 'A':
    printf("It was an a\n");
    break;
  case 'Q':
    printf("It was a q\n");
    break;
  default:
    printf("It was something else\n");    
  }
  printf("Bye now :)\n");      
  return 0;
}
