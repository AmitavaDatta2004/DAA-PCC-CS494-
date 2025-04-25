#include<stdio.h>

int maximum(int a,int b){
    if(a>b){
        return a;
    } else {
        return b;
    }
}

int knapsack(int n,int weights[],int profits[],int maxW){
    int i,w;
    int dpmatrix[n+1][maxW+1];

    for(i=0;i<n+1;i++){
        for(w=0;w<maxW+1;w++){
            if(i==0 || w==0){
                dpmatrix[i][w]=0;
            } else if(weights[i-1]<=w){
                dpmatrix[i][w]=maximum(dpmatrix[i-1][w],(dpmatrix[i-1][w-weights[i-1]]+profits[i-1]));
            } else {
                dpmatrix[i][w]=dpmatrix[i-1][w];
            }
        }
    }
    return dpmatrix[n][maxW];
}

int main(){
    int n,maxW;
    printf("Enter the no of items:");
    scanf("%d",&n);
    printf("Enter the knapsack capacity:");
    scanf("%d",&maxW);
    int weights[n],profits[n];

    int i;
    printf("Enter the weights and profits of all items:\n");
    for(i=0;i<n;i++){
        scanf("%d%d",&weights[i],&profits[i]);
    }

    int maxProfit=knapsack(n,weights,profits,maxW);
    printf("%d",maxProfit);
}