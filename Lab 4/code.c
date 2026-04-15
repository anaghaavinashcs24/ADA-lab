#include <stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int n, i, j, u, min, count, source;
    int G[MAX][MAX], dist[MAX], visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(count = 0; count < n - 1; count++)
    {
        min = INF;


        for(i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && G[u][j] != 0 &&
               dist[u] + G[u][j] < dist[j])
            {
                dist[j] = dist[u] + G[u][j];
            }
        }
    }

    printf("\nShortest distances from source:\n");
    for(i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
