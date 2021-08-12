#include <stdio.h> // printf
#include <math.h> // round
#define LOWER -50
#define UPPER 300
#define STEP 40

int main () {
  int t, dir = 1, ord = 0; // flags: dir for 1-4, ord 1-5

  if (dir == 0) { // Ex. 1-3 and 1-4
    printf("Fahr\t\tCels\n-------------------\n"); // print a header
  } else {
    printf("Cels\t\tFahr\n-------------------\n");
  }
  for (t = (ord == 1 ? LOWER : UPPER); // Ex. 1-5 up or down
       (t <= UPPER && ord == 1) || (t >= LOWER && ord != 1); // if (this and this) or (this and this)
       t += STEP * (ord == 1 ? 1 : -1)) { // increment or decrement depending on the direction
    printf("%3d\t=\t%3d\n", t, (int)round(dir == 0 ? 5 * (t - 32) / 9 : 9 * t / 5 + 32)); // mini-if cond ? true : false 
  }
  return 0;
}
