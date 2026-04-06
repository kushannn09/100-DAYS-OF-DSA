/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.*/
#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;
int dfs(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v))
                    return 1;
            }
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int m, u, v;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
