#include <stdio.h>
struct process{
    int id,at,bt,wt,tat,btt;
};
struct process a[10];

int queue[100];

int front =-1,rear=-1;

void insert(int n){
    if(front==-1)
    front=0;
    rear+=1;
    queue[rear]=n;
}
int delete(){
    int n;
    n = queue[front];
    front++;
    return n;
}
int main(){
    int n,tq,time=0,i,p;
    int temp[10],exist[10]={0};
    float ttat=0,twt=0;
    printf("Enter no of processes");
    scanf("%d",&n);
    printf("Enter time quanta");
    scanf("%d",&tq);
    for(i=0;i<n;i++){
        printf("Enter at bt ");
        scanf("%d%d",&a[i].at,&a[i].bt);
        a[i].id=i+1;
        a[i].btt=a[i].bt;
        temp[i]=a[i].bt;
    }
    
    insert(0);
    exist[0]=1;
    while(front<=rear){
        p=delete();
        if(a[p].bt>=tq){
            a[p].bt-=tq;
            time+=tq;
        }else{
            time +=a[p].bt;
            a[p].bt=0;
        }
        for(i=0;i<n;i++){
            if(exist[i]==0&&a[i].at<=time){
                insert(i);
                exist[i]=1;
            }
        }
        if(a[p].bt==0){
            a[p].tat=time-a[p].at;
            a[p].wt=a[p].tat-temp[p];
            ttat+=a[p].tat;
            twt+=a[p].wt;
        }else{
            insert(p);
        }
    }
    
    ttat/=n;
    twt/=n;
    printf("%f and %f ",ttat,twt);
    
    
    
}