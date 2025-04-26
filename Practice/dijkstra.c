#include<stdio.h>
#include<limits.h>

#define MAX 100
#define INF 99999
int graph[MAX][MAX];

int minDistance(int V,int dist[],int visited[]){
    int min=INF,minIndex=-1;
    int i;
    for(i=0;i<V;i++){
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void printSolution(int dist[],int src,int V){
    int i;
    for(i=0;i<V;i++){
        if(dist[i]==INF){
            printf("Unreachable\n");
        } else {
            printf("%d -->%d= %d\n",src,i,dist[i]);
        }
    }
}

void dijkstra(int V,int src,int dist[],int visited[]){
    int i;
    for(i=1;i<V;i++){
        int u = minDistance(V,dist,visited);
        if (u == -1){
            break;
        }
        visited[u]=1;
        int v;
        for(v=0;v<V;v++){
            if (visited[v]==0 && graph[u][v]!=0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist,src,V);


}



int main(){
    int V,src;
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    
    int i,j;
    printf("Enter the adjacency matrix:");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter the source:");
    scanf("%d",&src);

    int dist[V],visited[V];
    // int i;
    for(i=0;i<V;i++){
        dist[i]=INF;
        visited[i]=0;
    }
    dist[src]=0;

    dijkstra(V,src,dist,visited);

    return 0;
}