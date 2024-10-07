#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "forking.h"

int random_sleep_time() {
  return 1 + rand() % (8);
}

int main(int argc, char *argv[]) {
  const int num_things = atoi(argv[1]);
  const int pattern_num = atoi(argv[2]);

  pid_t pid = fork();
  printf("Number of things: %d, Pattern Number: %d\n", num_things, pattern_num);
  return 0;
}