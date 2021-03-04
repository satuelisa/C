#include <stdio.h>

int main() {
  int i, j, f = 0;

  printf("SIMPLE BREAK:\n");
  for (i = 0; i <= 10; i++) {
    for (j = i + 1; j <= 10; j++) { // this one
      if (2 * i == j) {
	break; // only break the INNER for
      }
      printf("%d %d\n", i, j);
    }
  }

  printf("\nFLAG BREAK:\n");
  /* how to break out of two or more loops */
  for (i = 0; f == 0 && i <= 10; i++) { // check flag
    for (j = i + 1; j <= 10; j++) {
      if (2 * i == j) {
	f = 1; // set flag
	break; 
      }
      printf("%d %d\n", i, j);
    }
  }

  printf("\nCONTINUE:\n");
  for (i = 0; i <= 10; i++) { 
    for (j = i + 1; j <= 10; j++) {
      if (2 * i == j) {
	continue; // skip THIS one only
      }
      printf("%d %d\n", i, j); // this is what gets skipped
    }
  }


  return 42;
}
