#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#define PE 3
#define UNAME 8

int main(int x, char** y) {
  char c;
  int i, count = 0;
  student** s;
  FILE* datos = fopen("datos.txt", "r");
  while ((c = fgetc(datos)) != EOF) {
    if (c == '\n') {
      count++; // chequemos cuantos van a ser
    }
  }
  printf("Parsing data for %d students...\n", count);
  s = (student**)malloc(sizeof(student*) * count);
  rewind(datos); // regresamos al inicio
  for (i = 0; i < count; i++) {
    s[i] = (student*)malloc(sizeof(student));
    s[i]->program = (char*)malloc(sizeof(char) * (PE + 1));
    s[i]->username = (char*)malloc(sizeof(char) * (UNAME + 1));
    fscanf(datos, "%u %s %s", &(s[i]->number), s[i]->program, s[i]->username);    
  }
  fclose(datos);
  for (i = 0; i < count; i++) {
    printf("Student %d %s (%u) is %s\n", (i + 1), s[i]->username, s[i]->number, s[i]->program);
    free(s[i]->program);
    free(s[i]->username);
    free(s[i]);
  }
  free(s);
  return 0;
}
