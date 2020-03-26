#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
int main()
{
 key_t key1;
 int shmid1;
 char *str1;
 key1 = ftok("/home/s0998dma/dipak/shm_key",'X');
 shmid1 = shmget(key1,2028,0666|IPC_CREAT);
 str1= (char *) shmat(shmid1,NULL,0);
 printf("key1 is : %x\n",key1);
 printf("ID is : %d\n",shmid1);
 printf ("Data read from shared memory is : %s \n",str1);
 shmdt(str1);
 shmctl(shmid1,IPC_RMID,NULL);
}
