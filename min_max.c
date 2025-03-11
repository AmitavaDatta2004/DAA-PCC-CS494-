
#include <stdio.h>
#include <limits.h>

// Function to find the minimum and maximum using divide and conquer
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    // If there's only one element, return it as both min and max
    if (low == high) {
        *min = *max = arr[low];
        return;
    }
    
    // If there are two elements, compare and assign min and max accordingly
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }
    
    // Divide the array into two halves
    int mid = (low + high) / 2;
    int min1, max1, min2, max2;
    
    // Recursively find min and max in the left half
    findMinMax(arr, low, mid, &min1, &max1);
    
    // Recursively find min and max in the right half
    findMinMax(arr, mid + 1, high, &min2, &max2);
    
    // Combine results: Find the overall min and max from both halves
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[100], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (n == 0) {
        printf("Array is empty. Please provide valid input.\n");
        return 0;
    }
    
    int min, max;
    findMinMax(arr, 0, n - 1, &min, &max);
    
    printf("Minimum Element: %d\n", min);
    printf("Maximum Element: %d\n", max);
    
    return 0;
}