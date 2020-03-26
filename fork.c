#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
 
 if(fork()>0)
   printf("Hello Child\n");
 else
   printf("Hello Parent\n");
 return 0;
}
