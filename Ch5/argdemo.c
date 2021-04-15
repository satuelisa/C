#include <stdio.h>
#include <stdlib.h>

#define DIM 3

void sum(int** m1, int** m2, int dim, int** target)  {
  int i, j;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      target[i][j] = m1[i][j] + m2[i][j];
    }
  }
  return;
}


void show(int** m, int dim)  {
  int i, j;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      printf("\t%d", m[i][j]);
    }
    printf("\n");
  }
  printf("----------\n");  
}

int main(int argc, char** args) {
  int i, j;
  int** matrix;
  int** another;
  int** result;
  
  for (i = 0; i < argc; i++) {
    printf("%s\n", *(args + i));
  }

  matrix = (int**)malloc(sizeof(int*) * DIM);
  another = (int**)malloc(sizeof(int*) * DIM);
  result = (int**)malloc(sizeof(int*) * DIM);
  for (i = 0; i < DIM; i++) {
    matrix[i] = (int*)malloc(sizeof(int) * DIM);
    another[i] = (int*)malloc(sizeof(int) * DIM);
    result[i] = (int*)malloc(sizeof(int) * DIM);
      for (j = 0; j < DIM; j++) {
	matrix[i][j] = (i * j + i + 2 * j) % 10;
	another[i][j] = (i * j + j + i * j) % 10;
	result[i][j] = 0;
      }
  }
  show(matrix, DIM);
  show(another, DIM);
  show(result, DIM);
  sum(matrix, another, DIM, result);
  show(result, DIM);  
  for (i = 0; i < DIM; i++) {
    free(matrix[i]);
    free(another[i]);
    free(result[i]);
  }
  free(matrix);
  free(another);
  free(result);
  return 1;
}
