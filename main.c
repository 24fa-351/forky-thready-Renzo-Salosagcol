#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int random_sleep_time() {
  return 1 + rand() % 8;
}

void pattern1(int num_things) {
  for (int process_num = 1; process_num <= num_things; process_num++) {
      if (fork() == 0) {
          // Child process
          fprintf(stderr, "Process %d (PID: %d) beginning\n", process_num, getpid());
          sleep(random_sleep_time());
          fprintf(stderr, "Process %d (PID: %d) exiting\n", process_num, getpid());
          exit(0);
      }
  }

  // Parent process waiting for children to exit
  while (wait(NULL) > 0);
}

void pattern2(int num_things, int process_num) {

  while (process_num <= num_things) {
    if (fork() == 0) {
      // Child process
      fprintf(stderr, "Process %d (PID: %d) beginning\n", process_num, getpid());

      if (process_num < num_things) {
        fprintf(stderr, "Process %d creating Process %d\n", process_num, process_num + 1);
        pattern2(num_things, process_num + 1);
      }
      
      sleep(random_sleep_time());
      fprintf(stderr, "Process %d (PID: %d) exiting\n", process_num, getpid());
      exit(0);
    }
    else {
      // Parent process waits for the child to complete
      wait(NULL);
      break;
    }
  }
  // Parent process waiting for children to exit
  while (wait(NULL) > 0);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
      fprintf(stderr, "Usage: %s <num_things> <pattern_num>\n", argv[0]);
      return 1;
  }

  const int num_things = atoi(argv[1]);
  const int pattern_num = atoi(argv[2]);
  FILE *results = freopen("results.txt", "a", stderr);
  setvbuf(stderr, NULL, _IONBF, 0);

  fprintf(stderr, "Running ./main with args %u and %d\n\n", num_things, pattern_num);

  srand(time(NULL));

  if (pattern_num == 1) {
    pattern1(num_things);
  } else if (pattern_num == 2) {
    pattern2(num_things, 1);
  }

  fprintf(stderr, "\nPROGRAM COMPLETE\n");
  fprintf(stderr, "\n******************************\n");

  fclose(results);
  return 0;
}
