#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
int main()
{
 key_t key;
 int shmid;
 char *str;
 char ch[] = "Testing Shared Memory IPC";
 key = ftok("/home/s0998dma/dipak/shm_key",'X');
 printf("key is : %x\n",key);
 shmid = shmget(key,2028,0666|IPC_CREAT);
 printf("ID is : %d\n",shmid);
 str= (char *) shmat(shmid,NULL,0);
 memcpy(str,ch,sizeof(ch));
 shmdt(str);
 return 0;
}
