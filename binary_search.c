#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int key,int low,int high){

    if(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            return binarySearch(arr,key,low,mid-1);
        }
        else if(arr[mid]<key){
            return binarySearch(arr,key,mid+1,high);
        }
    }
    return -1;
}


int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("Enter the key to be searched: ");
    scanf("%d",&key);

    int mid=binarySearch(arr,key,0,n-1);
    printf("mid=%d\n",mid);
    if(mid==-1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n",mid);
    }
}