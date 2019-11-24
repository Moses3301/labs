#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 3

//-------------------------------------------------------
void print_whoami(char *msg)
{
  printf("%s ==> my pid = %d  My Parent pid = %d\n",
         msg, getpid(), getppid());
}

//-------------------------------------------------------
void do_child(int j)
{
  srand(time(0));
  int sleep_time = (rand() % 100 * 1000) * ((getpid() %3) + 1);
  usleep(sleep_time);
  printf("child No. %d ==> my pid = %d  My Parent pid = %d\n", 
         j, getpid(), getppid());
  exit(0);
}

//-------------------------------------------------------
int main()
{
  char* hello_parent = "Hello from Parent";
  // char* hello_child = "Hello from Child";
  
  int pid, j, status;
  print_whoami(hello_parent);
  fflush(NULL);
    
  for (j = 1; j <= N; j++)
  {
    pid = fork();
    if (pid <0) 
    {
      perror("Cannot fork()") ;
      exit(EXIT_FAILURE) ;
    }
    if (pid == 0) // child process
      do_child(j);
  }
  // parent only
  for (j = 1; j <= N; j++)
  {
    wait(&status);
    printf("Parent pid %d: child %d just finished\n", getpid(), WEXITSTATUS(status));
  }    
  print_whoami(hello_parent);

  return 0;
}  
