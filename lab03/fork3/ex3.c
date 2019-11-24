#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>     // for fork, sleep etc.
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
a parent process reads a string from std input.
it creates two children:
  One of them converts the string to upper and prints to std-out
  The other child converts to Lower-Case, and prints to std-out
*/

void convert_2_upper(char *, int);
void convert_2_lower(char *, int);
void do_child(void (*func)(char*, int), char*, int, int); 
void printStr(char* str, int n); 

#define N 4
//-------------------------------------------------------
int main()
{
  int pid;
  int i, len;
  void (*func_ptr)(char*, int);
  char str[200];
  
  // compare what happens when the next line is commented out or not
  setbuf(stdout, NULL);
  
  puts("Enter a string (mix of upper and lower):");
  gets(str);
  len = strlen(str);
  
  
  for (i = 1; i <= N; i++)
  {
    if ((i%2)==0)
      func_ptr = convert_2_upper;
    else
      func_ptr = convert_2_lower;
      
    pid = fork();
    if (pid <0) 
    {
      perror("Cannot fork()") ;
      exit(EXIT_FAILURE) ;
    }
    if (pid==0)
    {
    
      do_child(func_ptr, str, len, i);
    } 
    else  // we could skip or omit this else-part
    {
      //do nothing...
    }
  }
  // this section for the parent only... the child doesn't return here (why?)
  return 0;
}  // end of main

//-------------------------------------------------------
void do_child(void (*func)(char*, int), char* str, int len, int num)
{
  // sleep(1);
  printf("hello from child #%d\n", num);
  func(str, len);
  //puts(str);
  printStr(str, len);
  exit(0);
}

//-------------------------------------------------------
void convert_2_upper(char* str, int n)
{
  int i;
  for (i=0; i<n; i++)
    if (str[i] >='a' &&  str[i] <='z')
      str[i]+='A'-'a';
}

//-------------------------------------------------------
void convert_2_lower(char* str, int n)
{
  int i;
  for (i=0; i<n; i++)
    if (str[i] >='A' &&  str[i] <='Z')
      str[i]+='a'-'A';
}

//-------------------------------------------------------
// this printStr prints string char by char
void printStr(char* str, int n)
{
  int i;
  for (i=0; i<n; i++)
  {
    putchar(str[i]);
    fflush(stdout);
  }
  putchar('\n');
  
}
