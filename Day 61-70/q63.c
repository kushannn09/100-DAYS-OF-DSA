/*Problem: Perform DFS starting from a given source vertex using recursion.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}
void DFS(Node* adj[], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(adj, visited, temp->vertex);
        }
        temp = temp->next;
    }
}
int main() {
    int n, m, u, v, s;
    scanf("%d", &n);

    Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    DFS(adj, visited, s);
    return 0;
}
