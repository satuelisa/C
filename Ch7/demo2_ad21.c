#include <stdio.h>
#include <ctype.h>

int main(int argc, char** values) {
  char c;
  FILE* source = fopen(values[1], "r"); // access a file
  FILE* target = fopen(values[2], "w"); // where to write
  while (!feof(source)) { // while it has content
    c = getc(source);
    if (isalpha(c)) {
      c = toupper(c);
    }
    putc(c, target);
  }
  fclose(source);
  fclose(target);
  return 1;
}
