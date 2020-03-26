
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThreadFun() 
{ 
    //sleep(1); 
    printf("Inside myThreadFun \n"); 
} 
   
int main() 
{
   int i; 
    pthread_t thread_id[5]; 
    printf("Before Thread\n"); 
    for(i=0;i<5;i++)
    {
        pthread_create(&thread_id[i], NULL, myThreadFun, NULL); 
        pthread_join(thread_id[i], NULL);

    }
    for(i=0;i<5;i++)
    {
        printf("inside main thread_id = %ld\n",thread_id[i]);
    }
    printf("After Thread\n");
    exit(0); 
}
