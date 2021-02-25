#include <stdio.h>
#include <stdlib.h> // atoi
#define TRUE 1
#define FALSE 0

int leap(y) {
  if ((y % 4 == 0 && y % 100 != 0)
      || (y % 400 == 0)) {
    return TRUE;
  }
  return FALSE;
}

int main(int c, char** s) {
  int year = atoi(s[1]); // s[0] is the executable name
  if (leap(year)) {
    printf("%d is a leap year\n", year);
  } else {
    printf("%d is NOT a leap year\n", year);
  }
  return 1;
}
