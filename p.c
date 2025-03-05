#include<stdio.h>


void mergeSort(int arr[],int left,int right , int mid){
    int i , j , k;
    int n1=mid-left+1;
    int n2=right-mid;

    int L[n1],R[n2];

    for(i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }

    i=0;
    j=0;
    k=0;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
            k++;
        }
        else{
            arr[k]=R[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }

}