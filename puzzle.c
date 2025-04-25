#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4
#define MAX 100000

// Goal state
int goal[SIZE][SIZE] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

typedef struct Node {
    int puzzle[SIZE][SIZE];
    int x, y; // Position of the blank tile (0)
    int g;    // Depth (cost so far)
    int h;    // Heuristic (misplaced tiles)
    struct Node* parent;
} Node;

// Check if the puzzle state matches the goal
int isGoal(int puzzle[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (puzzle[i][j] != goal[i][j])
                return 0;
    return 1;
}

// Count misplaced tiles
int calculateHeuristic(int puzzle[SIZE][SIZE]) {
    int misplaced = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (puzzle[i][j] != 0 && puzzle[i][j] != goal[i][j])
                misplaced++;
    return misplaced;
}

// Create a new node
Node* createNode(int puzzle[SIZE][SIZE], int x, int y, int newX, int newY, int g, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    memcpy(node->puzzle, puzzle, sizeof(node->puzzle));

    // Swap blank tile
    int temp = node->puzzle[x][y];
    node->puzzle[x][y] = node->puzzle[newX][newY];
    node->puzzle[newX][newY] = temp;

    node->x = newX;
    node->y = newY;
    node->g = g;
    node->h = calculateHeuristic(node->puzzle);
    node->parent = parent;
    return node;
}

// Print puzzle
void printPuzzle(int puzzle[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == 0) printf("   ");
            else printf("%2d ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// A* search
void solve(int initial[SIZE][SIZE]) {
    Node* open[MAX];
    int front = 0, rear = 0;

    // Find blank tile position
    int x, y;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (initial[i][j] == 0) { x = i; y = j; }

    Node* root = createNode(initial, x, y, x, y, 0, NULL);
    open[rear++] = root;

    while (front < rear) {
        // Find node with lowest f = g + h
        int minIndex = front;
        for (int i = front + 1; i < rear; i++) {
            int f1 = open[i]->g + open[i]->h;
            int f2 = open[minIndex]->g + open[minIndex]->h;
            if (f1 < f2) minIndex = i;
        }

        Node* current = open[minIndex];

        // Swap to front for removal
        open[minIndex] = open[front];
        open[front] = current;
        front++;

        if (isGoal(current->puzzle)) {
            printf("Solved using A* with Misplaced Tiles Heuristic:\n\n");

            // Print path
            Node* path = current;
            int steps = 0;
            while (path) {
                printPuzzle(path->puzzle);
                path = path->parent;
                steps++;
            }
            printf("Total steps: %d\n", steps - 1);
            return;
        }

        // Generate children
        for (int dir = 0; dir < 4; dir++) {
            int newX = current->x + dx[dir];
            int newY = current->y + dy[dir];

            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
                Node* child = createNode(current->puzzle, current->x, current->y, newX, newY, current->g + 1, current);
                open[rear++] = child;
            }
        }
    }

    printf("No solution found.\n");
}

// MAIN
int main() {
    int initial[SIZE][SIZE];

    printf("Enter the 15-puzzle initial state (use 0 for blank):\n");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &initial[i][j]);

    solve(initial);
    return 0;
}
