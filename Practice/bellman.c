#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF 99999

int graph[MAX][MAX];

void printSolution(int src,int dist[],int V){
    int i;
    for(i=0;i<V;i++){
        if(dist[i]==INF){
            printf("Vertext unreachable.\n");
        } else {
            printf("%d->%d=%d\n",src,i,dist[i]);
        }
    }
}

void belmanford(int src,int V,int dist[]){
    int i,u,v;
    for(i=0;i<V-1;i++){
        for(u=0;u<V;u++){
            for(v=0;v<V;v++){
                if( dist[u]!=INF && graph[u][v]!=0 && dist[u] +graph[u][v]<dist[v]){
                    dist[v]=dist[u]+graph[u][v];
                }
            }
        }
    }
    for(u=0;u<V;u++){
        for(v=0;v<V;v++){
            if( dist[u]!=INF && graph[u][v]!=0 && dist[u] +graph[u][v]<dist[v]){
                // dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(src,dist,V);
}

int main(){
    int V,src;
    printf("Enter the no of vertices:");
    scanf("%d",&V);

    printf("Enter the adjacency matrix:");
    int i,j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter the source vertex:");
    scanf("%d",&src);

    int dist[V];
    for(i=0;i<V;i++){
        dist[i]=INF;
    }
    dist[src]=0;
    belmanford(src,V,dist);
    return 0;
}