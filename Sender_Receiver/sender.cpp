gi#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define size 100
int main(){
    int shmid;
    key_t key;
    char *shm;
    key=1000;
    char *s;
    shmid=shmget(key,size,IPC_CREAT | 0666);
    shm=shmat(shmid,NULL,0);
    memcpy(shm,"Hello",5);
    
    s=shm;
    s+=5;
    *s=0;
    while(*shm != '*')
    sleep(1);
    
}
    
    
    
    
