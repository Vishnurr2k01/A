// Online C compiler to run C program online
#include <stdio.h>

int main() {
  int fno,pg[10],fr[10],i,j,k,pos,fault,p,flag;
  
  printf("Enter no of frames");
  scanf("%d",&fno);
    printf("Enter no of pages");
  scanf("%d",&p);
  
  printf("Enter page seq");
  
  for(i=0;i<p;i++){
      scanf("%d",&pg[i]);
  }
  for(i=0;i<fno;i++)
  fr[i]=-1;
  
  for(i=0;i<p;i++){
      flag=0;
      for(j=0;j<fno;j++){
          if(pg[i]==fr[i]){
              flag=1;
              break;
          }
      }
      if(flag==0){
          fr[pos]=pg[i];
          pos++;
          fault++;
      }
      if(pos>=fno){
          pos=0;
      }
  }
  printf("No of page faults : %d",fault);
}

