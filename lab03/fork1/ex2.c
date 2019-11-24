#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//-------------------------------------------------------
void print_whoami(char *msg)
{
  printf("%s ==> my pid = %d  My Parent pid = %d\n",
         msg, getpid(), getppid());
}

//-------------------------------------------------------
int main()
{
  char* hello_parent = "Hello from Parent";
  char* hello_child = "Hello from Child";

  int pid;
  print_whoami(hello_parent);
  fflush(NULL);


  pid = fork();
  if (pid <0)
  {
    perror("Cannot fork()") ;
    exit(EXIT_FAILURE) ;
  }
  if (pid == 0) // child process
  {
    print_whoami(hello_child);
    exit(0);
  } else
  {
    wait(NULL);  // change this call. See the impact
    print_whoami(hello_parent);
  }

  return 0;
}
