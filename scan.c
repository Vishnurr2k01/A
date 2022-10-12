// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rq[100],i,j,n,thm=0,initial,size,move;
    printf("enter the numebr of req");
    scanf("%d",&n);
     printf("enter the seq");
     for(i=0;i<n;i++)
    scanf("%d",&rq[i]);
    printf("enter the pos");
    scanf("%d",&initial);
    printf("enter the size");
    scanf("%d",&size);
    printf("enter the dir");
    scanf("%d",&move);
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
          if(rq[j]>rq[j+1]){
                int temp ;
            temp=rq[j];
            rq[j]=rq[j+1];
            rq[j+1]=temp;
          }
        }
    }
        int index;
        for(i=0;i<n;i++){
            if(rq[i]>initial){
                index=i;
                break;
        }
    }
    if(move==1){
        for(i=index;i<n;i++){
            thm+=abs(rq[i]-initial);
            initial = rq[i];
        }
        thm+=abs(size-rq[i-1]-1);
        initial = size-1;
    for(i=index;i>=0;i--){
            thm+=abs(rq[i]-initial);
            initial = rq[i];
        }
    }else{
        for(i=index-1;i>=0;i--){
            thm+=abs(rq[i]-initial);
            initial=rq[i];
        }
        thm+=abs(rq[i+1]-0);
        initial=0;
        for(i=index;i<n;i++){
            thm+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    
    printf("total head movement = %d ",thm);
    
    
    
    
    
    
    
    
    
    
}