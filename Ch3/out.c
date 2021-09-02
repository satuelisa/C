#include <stdio.h>

int main() {
  int i, j, flag = 0;

  for (i = 3; i < 10; i +=2) {
    printf("%d\n", i);
    if (i % 7 == 0) {
      break; // break the loop (do not repeat)
    }
  }
  i *= 5;
  while (i > 0) {
    i /= 2;
    if (i % 2 == 1) {
      continue; // jump to the next round
    }
    printf("%d\n", i);
  }
  i += 3;
  do { // at least once
    printf("hello, we have a %d\n", i--);
    for (j = 2 * i; j > 1; j--) {
      printf("at j = %d\n", j);
      if (j == 3) {
	flag = 1;
	break;
      }
    }
    if (flag) {
      break;
    }
  } while (i > 0);
  printf("bye :)\n");
  return 0;
}
