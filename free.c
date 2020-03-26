#include <stdio.h>
#include <stdlib.h>
int main()
{
        int n = 7;
        char *str;
        int *a;
        a   = (int *)malloc(n * sizeof(int));
        str = (char*) malloc(n * sizeof(char));
        int *length;
        length = str-8; 
        printf("Length of str:%d\n", *length);
        printf("Length of str:%d\n", malloc_usable_size(str));

  printf("%u\n", ((size_t *)a)[-1]); 
  printf("%u\n", malloc_usable_size(a));
  printf("%u\n", ((size_t *)str)[-1]);
  printf("%u\n", malloc_usable_size(str));
  free(str);
  free(a);
  exit(0);
}
