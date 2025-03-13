#include <stdio.h>
#include <limits.h>

// Function to compute the minimum number of scalar multiplications required
// to multiply a chain of matrices using a divide and conquer approach
int matrix_chain_order(int p[], int i, int j) {
    // Base case: If there is only one matrix, no multiplication is needed
    if (i == j)
        return 0;
    
    int min_count = INT_MAX;
    
    // Try all possible partitions and find the minimum cost
    for (int k = i; k < j; k++) {
        // Recursively calculate the number of multiplications for left and right subproblems
        int count = matrix_chain_order(p, i, k) +
                    matrix_chain_order(p, k + 1, j) +
                    p[i - 1] * p[k] * p[j];
        
        // Update the minimum cost if the current partition is better
        if (count < min_count)
            min_count = count;
    }
    
    return min_count;
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int dims[n + 1];
    printf("Enter the matrix dimensions (space-separated): ");
    
    // Read the dimensions of the matrices
    for (int i = 0; i <= n; i++)
        scanf("%d", &dims[i]);
    
    // Compute the minimum number of scalar multiplications
    int min_multiplications = matrix_chain_order(dims, 1, n);
    printf("Minimum number of scalar multiplications: %d\n", min_multiplications);
    
    return 0;
}