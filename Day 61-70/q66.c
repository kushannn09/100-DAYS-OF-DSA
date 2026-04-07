/*Problem: Detect cycle in directed graph using DFS and recursion stack.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }
    recStack[v] = 0;
    return 0;
}
int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
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
    }
    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
