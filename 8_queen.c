#include <stdio.h>
#include <stdbool.h>

#define N 8  // Size of the chessboard (8x8)

// Global variables
int board[N][N];         // The chessboard: 1 = queen, 0 = empty
int solutionCount = 0;   // Counter to keep track of solutions

// Function to print the board
void printBoard() {
    printf("Solution %d:\n", ++solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] == 1 ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col) {
    // Check the column above
    for (int i = 0; i < row; i++) //row =5
        if (board[i][col]==1)
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]==1)
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]==1)
            return false;

    return true;  // No conflicts — safe to place
}

// Recursive backtracking function to solve the problem
void solveNQueens(int row) {
    if (row == N) {
        // All queens placed successfully
        printBoard();
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;          // Place queen
            solveNQueens(row + 1);        // Recurse to next row
            board[row][col] = 0;          // Backtrack
        }
    }
}

// Main function
int main() {
    // Initialize the board with all 0s (no queens)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Start solving from the first row
    solveNQueens(0);

    // Print the total number of solutions found
    printf("Total number of solutions: %d\n", solutionCount);

    return 0;
}
