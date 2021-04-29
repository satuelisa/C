#include <stdio.h>
#include <stdlib.h>
#define PE 3
#define UNAME 8
#define ID 7
#define CONVERT 1
// #define DEBUG 1

int main(int x, char** y) {
  int k, i = 0;
  char username[UNAME + 1]; 
  char pr[PE + 1];
  char number[ID + 1];
  FILE* entrada = fopen("datos.txt", "r");
  FILE* salida = fopen("reorden.txt", "w");
  while (fscanf(entrada, "%s %s %s\n", number, pr, username) == 3) {
#ifdef CONVERT
    fprintf(salida, "Student %d %s (%d) is %s\n", ++i, username, atoi(number), pr);
#else
    fprintf(salida, "Student %d %s (%s) is %s\n", ++i, username, number, pr);
#endif
#ifdef DEBUG
    printf(".");
#endif
  }
#ifdef DEBUG
    printf("\n");
#endif    
  fclose(entrada);
  fclose(salida);
  return 0;
}
