#include <stdio.h>

int main() {
  int a = 13, b = 82, c = 5;

  c = (a < b) ? (c * 2) : (c - 1);
  printf("%d\n", c); 
  
  // rerun
  a = 13, b = 82, c = 5;
  
  if (a < b) {
    c *= 2;
  } else {
    c--;
  }
  printf("%d\n", c); 
  return 0;
}
