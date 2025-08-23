#include <stdio.h>

void foo(char *line) {
  int num, i = 0, len = 0;
  while (sscanf(line, "%d%n", &num, &len) == 1) {
    printf("Number %d is %d\n", i, num);
    line += len; // move pointer forward by number of characters read
    i++;
    len = 0; // reset len for next sscanf
  }
}

int main() {
  char test[] = "12 45 6 2 100   13";
  foo(test);
  return 0;
}
