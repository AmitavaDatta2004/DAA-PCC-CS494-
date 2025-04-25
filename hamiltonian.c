#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int graph[MAX][MAX];   // adjacency matrix
int path[MAX];         // stores current path of the cycle
int V;                 // number of vertices
int solutionCount = 0; // number of Hamiltonian cycles found

// Function to check if vertex v can be added at position 'pos'
bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false; // not adjacent to previous vertex

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false; // already included in the path
    }

    return true;
}

// Function to print a valid Hamiltonian cycle
void printSolution() {
    solutionCount++;
    printf("Cycle %d: ", solutionCount);
    for (int i = 0; i < V; i++)
        printf("V%d -> ", path[i] + 1);
    printf("V%d\n", path[0] + 1); // back to the starting vertex
}

// Recursive utility to generate all Hamiltonian cycles
void hamiltonianCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(); // found a cycle
        }
        return;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamiltonianCycleUtil(pos + 1);
            path[pos] = -1; // backtrack
        }
    }
}

// Main function
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // start at vertex 0
    printf("\nAll Hamiltonian Cycles:\n");
    hamiltonianCycleUtil(1);

    if (solutionCount == 0)
        printf("No Hamiltonian cycle found in the graph.\n");

    return 0;
}