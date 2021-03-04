#include <stdio.h>
#include <stdlib.h>


int main(int c, char** s) {
  int a = atoi(s[1]);
  char k = s[2][0];

  switch (a % 2) {
  case 0:
    printf("It is an even number.\n");
    break;
  case 1:
    printf("It is an odd number.\n");
    break;
  default:
    printf("The universe is broken.\n");
    break;    
  }

  switch (k) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'y':
    printf("It is a vowel.\n");
    break;
  default:
    printf("It is a consonant.\n");
    break;    
  }

  return 0;
}
