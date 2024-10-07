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
          printf("Process %d (PID: %d) beginning\n", process_num, getpid());
          sleep(random_sleep_time());
          printf("Process %d (PID: %d) exiting\n", process_num, getpid());
          exit(0);
      }
  }

  // Parent process waiting for children to exit
  while (wait(NULL) > 0);
}

void pattern2(int num_things) {
  for (int process_num = 1; process_num <= num_things; process_num++) {
      pid_t pid = fork();
      if (pid == 0) {
          // Child process
          printf("Process %d (PID: %d) beginning\n", process_num, getpid());
          sleep(random_sleep_time());
          printf("Process %d (PID: %d) exiting\n", process_num, getpid());
          exit(0);
      } else {
          // Parent process prints creating message before child process begins
          if (process_num < num_things) {
              printf("Process %d creating Process %d\n", process_num, process_num + 1);
          }

          // Parent process waits for the child to complete
          wait(NULL);
      }
  }
}

int main(int argc, char *argv[]) {
  const int num_things = atoi(argv[1]);
  const int pattern_num = atoi(argv[2]);

  srand(time(NULL));

  if (pattern_num == 1) {
    pattern1(num_things);
  } else if (pattern_num == 2) {
    pattern2(num_things);
  }

  return 0;
}
