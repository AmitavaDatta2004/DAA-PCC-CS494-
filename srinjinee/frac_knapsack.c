#include<stdio.h>

void swapInt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapDouble(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort to sort the array w.r.t. to the descending order of profit/weight ratio 

void sort(int weight[],int profit[],double ratio[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(ratio[j]<ratio[j+1]){
                swapDouble(&ratio[j],&ratio[j+1]);
                swapInt(&weight[j],&weight[j+1]);
                swapInt(&profit[j],&profit[j+1]);
            }
        }
    }
}

double fractional_knapsack(int weight[],int profit[],double ratio[],int n,double c){
    sort(weight,profit,ratio,n);
    double remaining_capacity = c;
    double MaxProfit = 0.0;
    for(int i=0;i<n;i++){
        if(remaining_capacity>=weight[i]){
            printf("\n taking the whole item---\n");
            MaxProfit += profit[i];
            remaining_capacity -= weight[i];
        }
        else{
            MaxProfit += profit[i]*(remaining_capacity/weight[i]);
            break;
        }
    }
    return MaxProfit;
}

int main(){
    int n;
    printf("\n Enter the number of items in the knapsack:");
    scanf("%d",&n);
    int weight[n],profit[n];
    double ratio[n];
    double c;
    printf("\n Enter the capacity of the knapsack:");
    scanf("%lf",&c);
    double maxProfit;
    for(int i=0;i<n;i++){
        printf("\n Enter the weight and profit of item[%d]:",i);
        scanf("%d%d",&weight[i],&profit[i]);
        ratio[i] = (double)profit[i]/weight[i];
    }
    maxProfit = fractional_knapsack(weight,profit,ratio,n,c);
    printf("\n The maximum profit will be = %.2lf",maxProfit);
    return 0;
}