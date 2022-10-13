// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char *str = (char*)shmat(shmid,(void*)0,0);
    printf("Enter string");
    scanf("%s",str);
    printf("\nData in memeory %s \n",str);
    shmdt(str);
    
    char *st = (char*)shmat(shmid,(void*)0,0);
    printf("\n data from memory %s",st);

    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
    
}