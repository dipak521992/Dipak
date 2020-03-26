#include <stdio.h>
#define TEMP "ABCD"
int main()
{ 
 char ptr[10] ={0} ;
 sprintf(ptr,"%s",TEMP);
 printf("%s\n",ptr);
 return 0;
}
