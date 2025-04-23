#include<stdio.h>
#include<stdlib.h>

int swapInt(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortJobs(int profit[],int deadline[],int jobNo[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i;j<n;j++){
            if(profit[i]<profit[j]){
                swapInt(&profit[i],&profit[j]);
                swapInt(&deadline[i],&deadline[j]);
                swapInt(&jobNo[i],&jobNo[j]);
            }
        }
    }
}

int maxDeadline(int deadline[],int n){
    int i;
    int max=0;
    for(i=0;i<n;i++){
        if(deadline[i]>max){
            max=deadline[i];
        }
    }
    return max;
}

int jobSequencing(int profit[],int deadline[],int jobNo[],int n){
    sortJobs(profit,deadline,jobNo,n);
    int maximum=maxDeadline(deadline,n);
    
    int slot[maximum];
    int i,j;
    for(i=0;i<n;i++){
        slot[i]=-1;
    }

    // jobNo= [3 , 2 , 1]
    // deadline= [3,2 , 1]
    // [-1,-1,3]3
    int maxProfit = 0;
    for(i=0;i<n;i++){
        for(j=deadline[i]-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=jobNo[i];
                maxProfit=maxProfit+profit[i];
                break;
            }
        }
    }

    for(i=0;i<maximum;i++){
        printf("Job-%d\n",slot[i]);
    }
    return maxProfit;
}

int main(){
    int n;
    printf("Enter the no of jobs:");
    scanf("%d",&n);

    int profit[n];
    int deadline[n];
    int jobNo[n];
    int i;
    for(i=0;i<n;i++){
        printf("Enter the profit and deadline of job %d",i+1);
        scanf("%d%d",&profit[i],&deadline[i]);
        jobNo[i]=i+1;
    }

    int maxProfit = jobSequencing(profit,deadline,jobNo,n);
    printf("%d",maxProfit);
    return 0;
}