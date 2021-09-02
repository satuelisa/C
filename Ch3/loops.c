#include <stdio.h>

int main() {
  int i;

  for (i = 3; i < 10; i +=2) {
    printf("%d\n", i);
  }

  while (i > 0) {
    i /= 2;
    printf("%d\n", i);    
  }
  i += 3;
  do { // at least once
    printf("hello, we have a %d\n", i--);    
  } while (i > 0);

  return 0;
}
