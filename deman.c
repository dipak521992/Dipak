#include <stdio.h>
int funct1()
{
 printf("Funct1\n");
 return  0;
}

int funct2()
{
 printf("Funct2 \n");
 return  0;

}

int main()
{
 int i = 0;
 printf ("dipak\n");
 i = funct1();
 i = funct2();
   printf ("dipak inside while loop \n"); 
return 0;
}
