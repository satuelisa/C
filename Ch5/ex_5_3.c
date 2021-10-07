#include <stdio.h>
int odd(int* data, int l) {
  return data[l/2];
}
int even(int* data, int l) {
  return (data[l/2] + data[l/2 + 1]) / 2;
}
int main() {
  int data[] = {2, 5, 6, 12, 74, 84, 333, 415};
  int length = 8;
  int(*use)(int*, int);
  switch (length % 2) {
  case 0:
    use = even;
    break;
  case 1:
    use = odd;
    break;
  }
  printf("%d\n", use(data, length));
}
