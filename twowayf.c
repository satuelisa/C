#include <stdio.h> // printf
#include <math.h> // round
#define LOWER -50
#define UPPER 300
#define STEP 40

void header(int); // Ex. 1-15
int conv(int, int);

int main () {
  int t, dir = 1, ord = 0; // flags: dir for 1-4, ord 1-5

  header(dir);
  for (t = (ord == 1 ? LOWER : UPPER); // Ex. 1-5 up or down
       (t <= UPPER && ord == 1) || (t >= LOWER && ord != 1); 
       t += STEP * (ord == 1 ? 1 : -1)) { 
    printf("%3d\t%3d\n", t, conv(t, dir));
  }
  return 0;
}

void header(int dir) {
  if (dir == 0) { // Ex. 1-3 and 1-4
    printf("F\tC\n--------------\n"); // print a header
  } else {
    printf("C\tF\n--------------\n");
  }
  return;
}

int conv(int v, int d) {
  return (int)round(d == 0 ? 5 * (v - 32) / 9 : 9 * v / 5 + 32);
}
