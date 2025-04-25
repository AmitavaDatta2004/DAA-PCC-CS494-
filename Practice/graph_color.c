#include<stdio.h>
#include<stdbool.h>

#define MAX 20
int graph[MAX][MAX];
int color[MAX];
int solution=0;
int V,n;

bool isSafe(int c,int v){
    int i;
    for(i=0;i<V;i++){
        if(graph[v][i]==1 && color[i]==c){
            return false;
        }
    }
    return true;
}

void printSolution(){
    solution ++;
    printf("Solution:%d\n",solution);
    int i;
    for(i=0;i<V;i++){
        printf("V%d->C%d",i+1,color[i]);
    }
    printf("\n");
}

void graphColoring(int v){
    if(v==V){
        printSolution();
        return;
    }

    int c;
    for(c=0;c<n;c++){
        if(isSafe(c,v)){
            color[v]=c;
            graphColoring(v+1);
            color[v]=-1;
        }
    }
}



int main(){
    int i,j;
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    printf("Enter the adjacency matrix(%dx%d):",V,V);
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter the no of color:");
    scanf("%d",&n);

    for(i=0;i<V;i++){
        color[i]=-1;
    }
    graphColoring(0);
    
    return 0;
}