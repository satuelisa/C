#include <stdio.h>

int main(int argc, char** values) {
  char c;
  FILE* source = fopen(values[1], "r"); // access a file
  int counter = 0;
  while (!feof(source)) { // while it has content
    c = getc(source); // read in character by character
    if (c == '\n') {
      counter++;
    }
  }
  fclose(source);
  printf("There were %d lines in the file\n", counter);  
  return 1;
}
