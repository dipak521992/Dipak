#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int i  = 0;
pthread_mutex_t lock; 
void *printOdd(void *arg)
{
    pthread_mutex_lock(&lock);
    for(i=1; i<=9;i = i+2)
    {
        printf("printOdd %d\n", i);
    }
    pthread_mutex_unlock(&lock);
    
}

void *printEven(void *arg)
{
    pthread_mutex_lock(&lock);
    for(i=2; i<=10; i = i+2)
    {
        printf("printEven %d\n", i);
    }
    pthread_mutex_unlock(&lock);

}
int main()
{
    pthread_t th_id1,th_id2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&th_id1,NULL,printOdd,NULL);
    pthread_create(&th_id2,NULL,printEven,NULL);

    pthread_join(th_id1,NULL);
    pthread_join(th_id2,NULL);
    
    printf("In side Main function\n");
    pthread_mutex_destroy(&lock); 
    return 0;
}
