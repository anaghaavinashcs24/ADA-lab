#include <stdio.h>

#define MAX 100

int parent[MAX];

// Find function
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void Union(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Sort edges by weight (bubble sort)
void sortEdges(int u[], int v[], int w[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                // swap weights
                int temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                // swap u
                temp = u[j];
                u[j] = u[j + 1];
                u[j + 1] = temp;

                // swap v
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, graph[MAX][MAX];
    int u[MAX], v[MAX], w[MAX]; // edge arrays
    int E = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        parent[i] = i; // initialize parent
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Convert adjacency matrix to edge list
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                u[E] = i;
                v[E] = j;
                w[E] = graph[i][j];
                E++;
            }
        }
    }

    // Sort edges
    sortEdges(u, v, w, E);

    int totalCost = 0;
    int count = 0;

    printf("\nEdges in MST:\n");

    // Kruskal's algorithm
    for (int i = 0; i < E && count < n - 1; i++) {
        int setU = find(u[i]);
        int setV = find(v[i]);

        if (setU != setV) {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            totalCost += w[i];
            Union(setU, setV);
            count++;
        }
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
