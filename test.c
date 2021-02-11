#include <stdio.h> // printf
#include <stdlib.h> // atoi

/*
 return type = integer = numero entero
 argc = how many command-line arguments do we have
 args = pointer to an ARRAY of the command-line arguments as character arrays
*/
int main(int loque, char** sea) { 
  int x, y, z; /* integer variables (storage space) */

  for (x = 0; x < loque; x++ ) {
    printf("%i: %s\n", x, sea[x]);
  }
  printf("3rd char of 1st string: %c\n", sea[0][2]);  

  x = atoi(sea[1]); // take an %s and make it into an %i
  y = atoi(sea[2]);
  z = atoi(sea[3]);
  printf("x is %i and y is %i and x * y is %i\n", x, y, x * y);
  printf("z is %i and x * z is %i\n", z, x * z);  

  z = x; // swap values
  x = y;
  y = z;

  if (x > y) { // condition
    printf("1st if: hello\n");
  }

  if (x < y) {
    printf("2nd if: first branch\n");
  } else {
    printf("2nd if: second branch\n");
  }

  if (x < y) {
    printf("3rd if: first branch\n");
  } else if (x < 2 * y) {
    printf("3rd if: second branch\n");
  } else {
    printf("3rd if: final branch\n");
  }

  z = x;
  while (x > 0) { // loop (cycle): check first, do later
    printf("while: %i\n", 2 * x); // print an integer
    x--; // lower by one
  }

  x = z;
  do { // do first, check the condition after
    printf("do-while: %i\n", 2 * x); // print an integer
    x--; // lower by one
  } while (x > 0);

  
  for (x = 1; x <= 5; x += 2) { // the complex order discussed on whiteboard
    printf("for: y - x = %i now and x = %i\n", y - x, x); // regular content
  }
  
  return 1;
}
