#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int is_prime(int n) {
  int i;
  if (n <= 1) {
    return 0;
  }
  for (i = 2; i <= n/2; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void print_primes() {
  int i;
  for (i = 2; i <= 100; i++) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

void print_fibonacci() {
  int i, n = 10, t1 = 0, t2 = 1, next_term;
  printf("Fibonacci Series: ");
  for (i = 1; i <= n; ++i) {
    printf("%d ", t1);
    next_term = t1 + t2;
    t1 = t2;
    t2 = next_term;
  }
  printf("\n");
}

int main() {
  pid_t pid;
  int status;

  pid = fork();

  if (pid == -1) {
    printf("Error: Failed to fork.\n");
    exit(1);
  } else if (pid == 0) {
    // child process
    print_fibonacci();
  } else {
    // parent process
    wait(&status);
    print_primes();
  }

  return 0;
}
