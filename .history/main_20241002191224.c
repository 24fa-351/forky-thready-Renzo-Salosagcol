#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int random_sleep_time() {
  return 1 + rand() % (8);
}

int main(int argc, char *argv[]) {
  const int num_things = atoi(argv[1]);
  const int pattern_num = atoi(argv[2]);
  
  for (int i = 0; i < num_things; i++) {
    printf("Printing index: %d of Process Number: %d\n", i, getpid());
  }

  return 0;
}