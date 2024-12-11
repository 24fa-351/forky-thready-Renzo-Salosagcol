#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const int num_things = atoi(argv[1]);
  const int pattern_num = atoi(argv[2]);

  fork();
  printf("Number of things: %d, Pattern Number: %d\n", num_things, pattern_num);
  return 0;
}