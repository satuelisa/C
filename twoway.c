#include <stdio.h> // printf
#include <math.h> // round
#define LOWER -50
#define UPPER 300
#define STEP 40

int main () {
  int t, dir = 1, ord = 0; // flag

  if (dir == 0) {
    printf("F\tC\n--------------\n");
  } else {
    printf("C\tF\n--------------\n");
  }
  for (t = (ord == 1 ? LOWER : UPPER);
       (t <= UPPER && ord == 1) || (t >= LOWER && ord != 1);
       t += STEP * (ord == 1 ? 1 : -1)) {
    printf("%3d\t%3d\n", t, (int)round(dir == 0 ? 5 * (t - 32) / 9 : 9 * t / 5 + 32));
  }
  return 0;
}
