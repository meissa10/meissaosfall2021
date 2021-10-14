#include  <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

void main(void){
  int pid;
  int x;
  srand(time(NULL));
  
  
  // first child loop
  for (x = 0; x < 2; x++){
     pid = fork();
    if (pid == 0){
      int sleeptimer = (rand() % 10) + 1;
      int timer = (rand() % 30) + 1;
      int x;
      // second child loop
      for (x = 0; x < timer; x++){
        printf("Child Pid: %d is going to sleep!", getpid());
        sleep(sleeptimer);
        printf("Child Pid: is awake!\nWhere is my Parent: %d?", getppid());
      }
      exit(0);
    }
   else if(pid > 0){
    int status = wait(&status);
    printf("Child Pid: %d has completed", status);
  }
   else{
    printf("Error");
    exit(0);
  }
  }


}