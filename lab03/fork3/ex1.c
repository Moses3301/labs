#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "colors.h"

int main()
{
  int pid;
  
  pid = fork();
  // printf("mypid=%d: just forked %d\n", getpid(), pid); 
  if (pid <0) 
  {
    perror("Cannot fork()") ;
    exit(EXIT_FAILURE) ;
  }
  if (pid==0)
  {
    printf("%sHello from Son pid=%d %s\n",RED, getpid(), NO_COLOR);
    exit(0);
  } else
  {
    printf("%sHello from Dad pid=%d %s\n",GREEN, getpid(), NO_COLOR);
  }
  return 0;
}  
