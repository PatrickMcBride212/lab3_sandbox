#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * readLine() {
  int bufSize = 64;
  int position = 0;
  char * buffer = malloc(sizeof(char) * bufSize);
  char c[2];
  if (!buffer) {
    fprintf(stderr, "line buffer allocation error\n");
  }
  while(1) {
    if (fgets(c, 2, stdin) == NULL) {
      exit(0);
    }
    if (c[0] == EOF) {
      exit(0);
    }
    if (c[0] == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c[0];
    }
    position++;
    if (position >= bufSize) {
      bufSize += bufSize;
      buffer = realloc(buffer, bufSize);
      if (!buffer) {
	fprintf(stderr, "Dynamic allocation error\n");
	exit(EXIT_FAILURE);
      }
    }
  }
}

int main() {
  while(1) {
    char * currentLine;
    currentLine = readLine();
    printf("%s\n", currentLine);
    if (strcmp(currentLine, "exit") == 0) {
      exit(0);
    }
  }
}
