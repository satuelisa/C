#include <stdio.h> // para printf
#define LO 0 // ahora con constantes
#define HI 300
#define S 20

int main() {
  float f; // menos variables

  for (f = LO; f <= HI; f += S) { 
    printf("%3.1fF\t=\t%6.2fC\n", f, 5.0 * (f - 32) / 9.0);
  }
  return 0;
}
