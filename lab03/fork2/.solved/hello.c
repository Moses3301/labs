#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>     // for fork, sleep etc.
#include <sys/types.h>
#include <sys/wait.h>

#define N 2  // change to 3, compile and run

//-------------------------------------------------------
void do_child()
{
  printf("hello \n");
}

//-------------------------------------------------------
int main()
{
  int pid;
  int i;
  
  for (i=0; i< N; i++)
  {
    pid = fork();
    if (pid <0) 
    {
      perror("Cannot fork()") ;
      exit(EXIT_FAILURE) ;
    }
    if (pid==0)
    {
      do_child();
      exit(0);
    } 
    else  // we could skip or omit this else-part
    {
      //do nothing...
    }
  }
  return 0;
}  

