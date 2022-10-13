#include <stdio.h>



int findlru(int time[],int f){
    int i,pos=0;
    int min = time[0];
    for(i=0;i<f;i++){
        if(time[i]<min)
        min=time[i];
        pos=i;
    }
    return pos;
    
}

int main(){
    int f,p,frame[100],pages[100],i,j,flag1,flag2,counter=0,time[100],fault=0,pos;
    
    printf("Enter no of page and fram");
    scanf("%d%d",&p,&f);
    printf("Enter the seq");
    for(i=0;i<p;i++){
        scanf("%d",&pages[i]);
    }
    for(i=0;i<f;i++){
        frame[i]=-1;
    }
    
    for(i=0;i<p;i++){
        flag1=0;flag2=0;
        for(j=0;j<f;j++){
            if(frame[j]==pages[i]){
                flag1=1;
                flag2=1;
                counter++;
                time[j]=counter;
                break;
            }
           
        }
         if(flag1==0){
                for(j=0;j<f;j++){
                    if(frame[j]==-1){
                        frame[j]=pages[i];
                        flag2=1;
                        counter++;
                        time[j]=counter;
                        fault++;
                        break;
                    }
                }
            }
        if(flag2==0){
            pos=findlru(time,f);
            frame[pos]=pages[i];
            counter++;
            time[pos]=counter;
            fault++;
        }
      printf("%d | ",pages[i]);
      for(j=0;j<f;j++){
          printf("%d ", frame[j]);
          
      }
      printf("\n");
        
    }
    printf("fault %d",fault);
    
}