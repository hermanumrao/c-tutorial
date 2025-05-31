#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(char *i, char *j) {
  char tmp = *i;
  *i = *j;
  *j = tmp;
}

char *reverse_str(char *input, char del) {
  char *start = input;
  char *end = input;
  while (*end != del && *end != '\0') {
    end++;
  }
  char *last = end;
  end--;
  while (start < end) {
    swap(start, end);
    start++;
    end--;
  }
  return last;
}

int main(int argc, char *argv[]) {
  char input[] = "i am herman";
  char *start = input;
  char *end = reverse_str(input, '\0');
  printf("%s \n", input);
  while (start < end) {
    start = reverse_str(start, ' ');
    if (*start == ' ')
      start++;
  }
  printf("%s \n", input);

  return EXIT_SUCCESS;
}
