/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <limits.h>
#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int graph[MAX][MAX];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }
    int src;
    scanf("%d", &src);

    int dist[MAX], visited[MAX];

    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        int min = INT_MAX, u;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(int v = 0; v < n; v++) {
            if(graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", dist[i]);
    return 0;
}
