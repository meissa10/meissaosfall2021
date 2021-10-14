#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int x = 0;

void begin(int y){
  x++;
  printf("%d seconds", x);
  alarm(1);
}

void end(int y){
  printf("The program ran %d seconds", x);
  exit(0);
}

int main(int argc, char * argv[]){
  signal(SIGALRM, begin);
  signal(SIGINT, end);
  alarm(1);
  while(1);
  return 0;
}