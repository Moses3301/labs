#include<stdio.h>
#include<stdlib.h>

char* get_name() {
 char *name = malloc(10);
 puts("enter your name:");
 gets(name);
 return name;
}

