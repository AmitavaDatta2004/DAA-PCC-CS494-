#include<stdio.h>
#include<stdlib.h>

void swapInt(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapDouble(double * a , double * b ){
    double temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(int profit[],int weight[],double ratio[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                swapDouble(&ratio[i],&ratio[j]);
                swapInt(&profit[i],&profit[j]);
                swapInt(&weight[i],&weight[j]);
            }
        }
    }
}

double fractional_knapsack(int profit[],int weight[],double ratio[],int n,double capacity){
    sortItems(profit,weight,ratio,n);

    int i;

    double maxProfit=0.0;
    double remainingCapacity=capacity;
    for(i=0;i<n;i++){
        if(remainingCapacity>=weight[i]){
            maxProfit=maxProfit+profit[i];
            remainingCapacity=remainingCapacity-weight[i];
        } else {
            maxProfit=maxProfit+(remainingCapacity/weight[i])*profit[i];
            break;
        }
    }
    return maxProfit;
}

int main(){
    int n;
    printf("Enter the no of objectsL:");
    scanf("%d",&n);

    int weight[n];
    int profit[n];
    double ratio[n];




    int i;
    for(i=0;i<n;i++){
        printf("Enter the weight and profit of object %d :",i+1);
        scanf("%d%d",&weight[i],&profit[i]);
        ratio[i]=(double)profit[i]/weight[i];
    }

    double capacity;
    printf("Enter the capacity:");
    scanf("%lf",&capacity);

    double maxProfit=fractional_knapsack(profit,weight,ratio,n,capacity);
    printf("Max proifit is %.2lf",maxProfit);
}