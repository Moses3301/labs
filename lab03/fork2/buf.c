#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>     // for fork, sleep etc.
#include <sys/types.h>
#include <sys/wait.h>

#define N 2  // change to 3, compile and run

//-------------------------------------------------------
void do_child(int j)
{
  printf(" ### CHILD %d hello ### \n", j);
  exit(0);
}

//-------------------------------------------------------
int main()
{
  int pid;
  int i;

  printf("*** PARENT STARTING ***\n");

  for (i=1; i<= N; i++)
  {
    fflush(NULL);
    pid = fork();
    if (pid <0)
    {
      perror("Cannot fork()") ;
      exit(EXIT_FAILURE) ;
    }
    if (pid==0)
    {
      do_child(i);
    }
  }

  for (i=1; i<= N; i++)
    wait(NULL);
  printf(" *** PARENT ENDING ***");


  return 0;
}
