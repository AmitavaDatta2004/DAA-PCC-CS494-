#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int i , j , k;

    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[left+i];
    }

    for(j=0;j<n2;j++){
        R[n2]=arr[mid+1+j];
    }

    i=0;
    j=0;
    k=left;

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

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test Merge Sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Example input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    printf("Original array: \n");
    printArray(arr, n); // Print original array

    // Call mergeSort to sort the array
    mergeSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n); // Print sorted array

    return 0; // End program
}