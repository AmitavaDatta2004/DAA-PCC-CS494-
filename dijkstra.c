#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 99999

int minDistance(int dist[], int visited[], int V) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printSolution(int dist[], int V, int src) {
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d \t Unreachable\n", i);
        else
            printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[V];
    int visited[V];

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // visited=[0,0,0,...]
    
    dist[src] = 0;
    // dist=[0,inf,inf,inf,...]

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break; // no more reachable nodes
        visited[u] = 1;
        // visited=[1,0,0,...]

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
        // visited=[0,4,3,inf,...]
    }

    printSolution(dist, V, src);
}

int main() {
    int V, graph[MAX][MAX], src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);
    return 0;
}
