#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int graph[MAX][MAX];
int color[MAX];
int V, m;
int solutionCount = 0;

bool isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

void printSolution() {
    solutionCount++;
    printf("Solution %d: ", solutionCount);
    for (int i = 0; i < V; i++) {
        printf("V%d:C%d ", i + 1, color[i]);
    }
    printf("\n");
}

void graphColoring(int v) {
    if (v == V) {
        printSolution();
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            graphColoring(v + 1);
            color[v] = 0;
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize all vertex colors to 0
    for (int i = 0; i < V; i++)
        color[i] = 0;

    printf("\nAll possible colorings:\n");
    graphColoring(0);

    if (solutionCount == 0)
        printf("No solution exists with %d colors.\n", m);

    return 0;
}