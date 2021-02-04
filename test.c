#include <stdio.h> // standard input and output

int main(int argc, char** args) { // we will talk about this stuff later
  int x, y, z; // integers

  x = 13; // define initial values
  y = 7;

  z = x; // swap values
  x = y;
  y = z;

  if (x > y) {
    printf("hello\n");
  }

  while (x > 0) { // loop (cycle)
    printf("%i\n", 2 * x); // print an integer
    x--; // lower by one
  }
  
  return 1;
}
