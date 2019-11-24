#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

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
  
  //   create a child process. each parent and child needs to prints his message
  //   by running the following commands:
  //   print_whoami(hello_child);
  //   print_whoami(hello_parent);    
  
  pid = fork();
  if (pid <0) 
  {
    perror("Cannot fork()") ;
    exit(EXIT_FAILURE) ;
  }
  // fill you code here, compile and run

  return 0;
}  
