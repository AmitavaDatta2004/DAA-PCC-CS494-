#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place pivot at the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Pointer for smaller element

    // Traverse through the array
    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Move the pointer for smaller element
            swap(&arr[i], &arr[j]); // Swap elements
        }
    }
    // Place the pivot at the correct sorted position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return pivot index
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the partition index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test Quick Sort
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // Example input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    printf("Original array: \n");
    printArray(arr, n); // Print original array

    quickSort(arr, 0, n - 1); // Call Quick Sort function

    printf("Sorted array: \n");
    printArray(arr, n); // Print sorted array

    return 0; // End program
}
