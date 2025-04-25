#include<stdio.h>
#include<stdbool.h>

#define MAX 20
int graph[MAX][MAX];
int path[MAX];
int V;
int solution;

bool isSafe(int v,int pos){
    if (graph[path[pos-1]][v]==0){
        return false;
    }

    int i;
    for(i=0;i<pos;i++){
        if(path[i]==v){
            return false;
        }
    }
    return true;
}

void printSolution(){
    solution++;
    int i;
    printf("Hamiltonian cycle - %d",solution);
    for(i=0;i<V;i++){
        printf("V%d-->",path[i]);
    }
    printf("V%d\n",path[0]);
}

void hamiltonian(int pos){
    if(pos==V && graph[path[pos-1]][path[0]]==1){
        printSolution();
        return;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamiltonian(pos + 1);
            path[pos] = -1; // backtrack
        }
    }


}



int main(){
    printf("Enter the no of vertices:");
    scanf("%d",&V);

    printf("Enter the adjacency matrix:\n");
    int i , j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    for(i=0;i<V;i++){
        path[i]=-1;
    }
    path[0]=0;
    hamiltonian(1);

    if(solution==0)
    printf("No solution");
    return 0;
}