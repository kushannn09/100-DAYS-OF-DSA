/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.*/
#include <stdio.h>
#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u[1000], v[1000], w[1000];
    for(int i = 0; i < m; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    int src;
    scanf("%d", &src);
    int dist[1000];

    for(int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;
  
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]])
                dist[v[j]] = dist[u[j]] + w[j];
        }
    }
    for(int j = 0; j < m; j++) {
        if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    return 0;
}
