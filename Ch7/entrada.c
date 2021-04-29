#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#define PE 3
#define UNAME 8

int main(int c, char** d) {
  int i, count;
  student** s;
  printf("How many students are there? ");
  scanf("%d", &count);
  printf("Collecting data for %d students...\n", count);
  s = (student**)malloc(sizeof(student*) * count);
  for (i = 0; i < count; i++) {
    s[i] = (student*)malloc(sizeof(student));
    printf("What are the student ID number, study program, and username for student %d? ", (i + 1));
    s[i]->program = (char*)malloc(sizeof(char) * (PE + 1));
    s[i]->username = (char*)malloc(sizeof(char) * (UNAME + 1));
    scanf("%u %s %s", &(s[i]->number), s[i]->program, s[i]->username);
    printf("\n");
  }
  for (i = 0; i < count; i++) {
    printf("Student %d %s (%u) is %s\n", (i + 1), s[i]->username, s[i]->number, s[i]->program);
    free(s[i]->program);
    free(s[i]->username);
    free(s[i]);
  }
  free(s);
  return 0;
}
