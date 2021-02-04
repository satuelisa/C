#include <stdio.h> // standard input and output

int main(int argc, char** args) { // we will talk about this stuff later
  int x, y, z; // integers

  x = 3; // define initial values
  y = 7;

  z = x; // swap values
  x = y;
  y = z;

  if (x > y) {
    printf("if: hello\n");
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
