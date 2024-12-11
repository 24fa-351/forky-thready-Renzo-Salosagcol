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

  switch (pattern_num) {
    case 1:
      forking1(num_things);
      break;
    
    case 2:
      forking2(num_things);
      break;
    
    case 3:
      forking3(num_things);
      break;
    
    default:
      perror("Default case is matched. No forking methods occurred");
      break;
  }

  return 0;
}