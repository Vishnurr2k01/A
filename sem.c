// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int mutex=1,full=0,empty=3,x=0;


int main(){
    int n;
    int signal();
    int wait();
    void producer();
    void consumer();
    
     printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
 while(1) 
 {
 printf("\nENTER YOUR CHOICE\n");
 scanf("%d",&n);
 switch(n)
 { case 1:
 if((mutex==1)&&(empty!=0))
 producer();
 else
 printf("BUFFER IS FULL\n");
 break; 
 case 2:
 if((mutex==1)&&(full!=0))
 consumer();
 else
 printf("BUFFER IS EMPTY\n");
 break;
 case 3:
 exit(0);
 break;
 }
 } 

}
int signal(int s){
    return ++s;
}
int wait(int s){
    return --s;
}

void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
 printf("producer produces the item%d\n",x);
 mutex=signal(mutex);
}

void consumer(){
    mutex=wait(mutex);
    empty=signal(empty);
    full=wait(full);
    printf("consumer consumes item%d\n",x);
    x--;
    mutex=signal(mutex);
    
}
