#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

int largo(char* str) {
  int counter = 0;
  while (*str != '\0') {
    counter++; // contando caracteres
    str++; // avanzando el puntero al siguiente caracter
  }
  return counter;
}

int mas_padre(char* str) {
  int counter = 0;
  while (*(str + counter) != '\0') {
    counter++; // contando caracteres
  }
  return counter;
}

int main() {
  int data[SIZE];
  int pos = 2;
  char* prueba = "hola mundo";

  printf("%s %d = %d\n", prueba, largo(prueba), mas_padre(prueba));
  data[pos] = 13;
  printf("%d\n", data[pos]);  
  *(data + pos) = 14;
  printf("%d\n", data[pos]);
  
  
  return 1;
}
