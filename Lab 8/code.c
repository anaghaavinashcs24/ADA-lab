#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return item;
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    int indegree[n];

    // Read adjacency matrix
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 1) {
                indegree[j]++;  // Count incoming edges
            }
        }
    }

    Queue q;
    initQueue(&q);

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    printf("Topological Ordering: ");
    int count = 0;

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);
        count++;

        // Reduce indegree of neighbors
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph has a cycle, topological ordering not possible.\n");
    } else {
        printf("\n");
    }

    return 0;
}
