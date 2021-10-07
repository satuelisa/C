
#include <stdio.h>
#include <stdlib.h> // malloc & free

#define DIM 3

void lemme_see(int** m)  {
  int i, j;
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      printf(" %d", m[i][j]);
    }
    printf("\n");
  }
  return;
}

int main() {
  
  int** m = NULL;
  int* row = NULL;
  int i, j;
  m = (int**)malloc(DIM * sizeof(int*));
  for (i = 0; i < DIM; i++) {
    m[i] = (int*)malloc(DIM * sizeof(int));
  }

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      // *(*(m + i) + j) = DIM * i + j + 1;
      m[i][j] = DIM * i + j + 1;
    }
  }

  // m[1][1] = 0;
  *(*(m + 1) + 1) = 0;
  lemme_see(m);
  
  for (i = 0; i < DIM;) {
    free(m[i++]);
  }
  free(m);
  return 42;
}
