#include <stdio.h> // printf
#include <math.h> // round
#define LOWER -50
#define UPPER 300
#define STEP 40

int main () {
  int t, direction = 1;

  if (direction == 0) {
    printf("F\tC\n--------------\n");
  } else {
    printf("C\tF\n--------------\n");
  }
  for (t = LOWER; t <= UPPER; t += STEP) {
    printf("%3d\t%3d\n", t, (int)round(direction == 0 ? 5 * (t - 32) / 9 : 9 * t / 5 + 32));
  }
  return 0;
}
