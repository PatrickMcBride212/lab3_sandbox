#include <stdio.h>
#include <stdlib.h>

int main() {
  char line[500];
  while(1) {
    if (fgets(line, 500, stdin) == NULL) {
      exit(0);
    } else {
      printf("%s", line);
    }
  }
}
