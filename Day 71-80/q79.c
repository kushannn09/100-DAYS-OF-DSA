/*Problem Statement: Find shortest distances from source vertex in a weighted graph with non-negative weights.*/
#include <stdio.h>
#include <limits.h>
#define V 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int graph[V][V], int n, int src) {
    int dist[V], visited[V];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n = 5, m = 6;
    int graph[V][V] = {0};

    graph[1][2] = 2;
    graph[1][3] = 4;
    graph[2][3] = 1;
    graph[2][4] = 7;
    graph[3][5] = 3;
    graph[4][5] = 1;

    int source = 1;
    dijkstra(graph, n, source);

    return 0;
}

