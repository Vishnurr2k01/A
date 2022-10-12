// Online C compiler to run C program online
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int alloc[5][5],avail[5],max[5][5],n,m;
void input();
int main() {
    int i,j,k;
  input();
int y,f[n];
    int need[n][m];
    int ind;
    for(i=0;i<n;i++){
        f[i]=0;
    }
    int ans[n];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
           need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(k=0;k<5;k++){
        for(i=0;i<n;i++){
            if(f[i]==0){
                int flag =0;
                for(j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag = 1;
                        break;
                    }
            
                }
                if(flag==0){
                    ans[ind++]=i;
                    for(y=0;y<m;y++){
                        avail[y]+=alloc[i][y];
                        f[i]=1;
                    }
                }
            }
        }
    }
    
    
int flag = 1;
for(int i=0;i<n;i++)
{
 if(f[i]==0)
 {
flag=0;
printf("The following system is not safe");
break;
 }
}
if(flag==1)
{
 printf("The safe sequence is :\n");
 for (i = 0; i < n - 1; i++)
printf(" P%d ->", ans[i]);
 printf(" P%d\n", ans[n - 1]);
}
 
  
}

void input(){
    int i,j;
    printf("Enter number of processes and instances");
    scanf( "%d%d",&n,&m);
    printf("enter the alloc matrix");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
     printf("enter the max matrix");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
     printf("enter the avail matrix");
    for(i=0;i<m;i++){
       
            scanf("%d",&avail[i]);
        
    }
    
}

