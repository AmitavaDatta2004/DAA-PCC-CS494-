#include<stdio.h>
#include<limits.h>

#define MAX 100 
#define INF 99999 

int graph[MAX][MAX];

void printSolution(int dist[],int V,int src){
    for(int i=0;i<V;i++){
        if(dist[i] == INF){
            printf("\n Unreachable");
        }
        else{
            printf("V%d -> V%d : %d",src,i,dist[i]);
        }
    }
}
void bellmanFord(int dist[],int V,int src){
    // (V-1) times relaxation of edges
    for(int i=0;i<V-1;i++){
        //iterate through each row u and column v of graph[MAX][MAX]
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(dist[u] != INF && graph[u][v]!=0 && dist[u]+graph[u][v] < dist[v]){
                    dist[v] = dist[u]+graph[u][v];
                }
            }
        }
    }
    // negative edge cycle detection 
    for(int u=0;u<V;u++){
        for(int v=0;v<V;v++){
            if(dist[u]!= INF && graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v]){
                printf("\n This graph contains negative edge cycle.");
            }
        }
    }

    printSolution(dist,V,src);
}

int main(){
    int V,src;
    printf("\n Enter the no of vertices:");
    scanf("%d",&V);
    int dist[V];
    printf("\n Enter the adjacency matrix of the graph :");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\n Enter the source vertex:");
    scanf("%d",&src);

    // initialization of distance array 
    for(int i=0;i<V;i++){
        dist[i] = INF;
    }

    bellmanFord(dist,V,src);
    return 0;

}