#include<stdio.h>
struct process{
	int AT,BT,WT,TAT,P;
}a[10];
void main(){
	int n,i,temp1[100],temp2[100],t,highest=0,count=0,total_WT=0,total_TAT=0,finish[100],k=0;
	float avg_WT,avg_TAT;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter arrival time, burst time, and priority of each process:\n");
	for(i=0;i<n;i++){
		printf(" Process %d:\n",i);
		printf("  Arrival Time: ");
		scanf("%d",&a[i].AT);
		printf("  Burst Time: ");
		scanf("%d",&a[i].BT);
		temp1[i]=a[i].BT;
		printf("  Priority: ");
		scanf("%d",&a[i].P);
		temp2[i]=a[i].P;
	}
	int prio=100;
	for(t=0;count!=n;t++){
		for(i=0;i<n;i++){
			if(a[i].P<prio && a[i].BT>0 && a[i].AT<=t){
				highest=i;
				prio=a[i].P;
			}
		}
		a[highest].BT--;
		if(a[highest].BT==0){
			count++;
			finish[k]=highest;
			prio=1000;
			k++;
			a[highest].TAT=t+1-a[highest].AT;
			a[highest].WT=a[highest].TAT-temp1[highest];
			total_WT+=a[highest].WT;
			total_TAT+=a[highest].TAT;
		}
	}
	avg_WT=total_WT/(n*1.00);
	avg_TAT=total_TAT/(n*1.00);
	printf("Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurn Around Time\n");
	for(i=0;i<n;i++){
		printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",finish[i],a[finish[i]].AT,temp1[finish[i]],temp2[finish[i]],a[finish[i]].WT,a[finish[i]].TAT);
	}
	printf("\nAverage Waiting Time: %.2f\n",avg_WT);
	printf("Average Turn Around Time: %.2f\n",avg_TAT);
}
