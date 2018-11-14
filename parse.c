#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "parse.h"

char** parse_args(char* line) {
  char** args = calloc(sizeof(char*), 6);
  int index = 0;
  while (line != NULL && index < 5) {
    args[index] = strsep(&line, " ");
    index++;
  }
  return args;
}

int main() {
  char* line = calloc(sizeof(char), 100);
  strcpy(line, "ls -a -1 .");
  char** args = parse_args(line);
  int i = 0;
  printf("parsed:\n");
  for ( ; i < 6; i++) {
    printf("\targs[%d]: | %s |\n", i, args[i]);
  }
  int msg = execvp(args[0], args);
  if (msg == -1) {
    printf("%s\n", strerror(errno));
  }
  free(args);
  free(line);
  return 0;
}
