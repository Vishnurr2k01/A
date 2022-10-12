// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int at[10]={0},bt[10]={0},tat[10],wt[10],ct[10],n,i,order[10]={0},temp,ttat,twt;
float f_tat,f_twt;

void swap(int *x,int *y){
    int temp = *x;
    *x=*y;
    *y = temp;
}

void sort(int arr[],int n){
    int i,j;
    
    for( i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&order[i],&order[j]);
            }
        }
    }
    
    
}

int main() {

printf("Enter no of processes");
scanf("%d",&n);
for(i=1;i<=n;i++){
    printf("Arrival time of process");
    scanf("%d",&at[i]);
    printf("burst time processes");
      scanf("%d",&bt[i]);
      order[i]=i;
    
}
sort(at,n);

for(i=1;i<=n;i++){
    if(i==1){
        temp = at[i]+bt[i];
        ct[i]=temp;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        ttat+=tat[i];
        
    }else{
        temp+=bt[i];
        ct[i]=temp;
       tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        if(wt[i]<0){
            ct[i]+=abs(wt[i]);
            temp=ct[i];
            tat[i]+=abs(wt[i]);
            wt[i]=0;
        }
        ttat+=tat[i];
        twt+=wt[i];
    }
    
 

    
}
   f_tat=ttat/n;
    f_twt=twt/n;
     printf("\norder in which process get executed :\t");
 for (i = 1; i <= n; i++)
 {
 printf("%d \t ", order[i]);

 }
  printf("\n\nAverage waiting time is %.2f", f_twt);
 printf("\nAverage turn around time is is %.2f\n", f_tat);








    return 0;
}