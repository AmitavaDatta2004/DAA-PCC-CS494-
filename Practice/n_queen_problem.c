#include<stdio.h>
#include<stdbool.h>

#define N 8
int board[N][N];
int solution = 0;

void printSolution(){
    int i,j;
    solution++;
    printf("Solution no : %d -->\n",solution);

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(board[i][j]==1){
                printf(" Q ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row, int column){ // Assuming a maximum size of 10 for the board
    int i , j;
    for(i=0;i<row;i++){
        if(board[i][column]==1){
            return false;
        }
    }

    for(i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    
    for(i=row-1,j=column+1;i>=0 && j<N;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }

    return true;
}

void solveNQueen(int row){
    if(row==N){
        printSolution();
        return;
    }
    int i;
    for(i=0;i<N;i++){
        if(isSafe(row,i)){
            board[row][i]=1;
            solveNQueen(row+1);
            board[row][i]=0;
        }
    }

}

int main(){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            board[i][j]=0;
        }
    }

    // int solutions=0;
    solveNQueen(0);
    printf("Total no of solutions : %d",solution);
    return 0;
}