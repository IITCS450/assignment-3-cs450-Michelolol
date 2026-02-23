#include "types.h"
#include "stat.h"
#include "user.h"

void work() {
  for (int i = 0; i < 5000; i++) {
    for (int j = 0; j < 10000000; j++) {
       asm("nop"); 
    }
  }
}

int main(void) {
  int tickets[] = {10, 20, 30};
  
  printf(1, "Starting\n");

  for (int i = 0; i < 3; i++) {
    int pid = fork();
    if (pid < 0) exit();
    if (pid == 0) {
      settickets(tickets[i]); 
      work();
      printf(1, "Process with %d tickets finished.\n", tickets[i]);
      exit();
    }
  }

  for (int i = 0; i < 3; i++) wait();
  exit();
}