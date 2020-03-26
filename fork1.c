#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int a = 10;
int main()
{
 a++; 
 if(fork()>0)
 {
   printf("Hello Child : %d\n",a);
 }
 else
 {
   printf("Hello Parent : %d\n",a);
 }
 return 0;
}
