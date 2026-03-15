/*Problem Statement: Construct a Binary Tree from the given level-order traversal.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
Node* q[10005];
int front = 0, rear = -1;

void enqueue(Node* node) { q[++rear] = node; }
Node* dequeue() { return q[front++]; }
int isEmpty() { return front > rear; }

void printInorder(Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int a[10005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 0 || a[0] == -1) {
        printf("\n");
        return 0;
    }
    Node* root = newNode(a[0]);
    enqueue(root);
    int i = 1;
    while (!isEmpty() && i < n) {
        Node* curr = dequeue();
        if (i < n && a[i] != -1) {
            curr->left = newNode(a[i]);
            enqueue(curr->left);
        }
        i++;
        if (i < n && a[i] != -1) {
            curr->right = newNode(a[i]);
            enqueue(curr->right);
        }
        i++;
    }
    printInorder(root);
    printf("\n");
    return 0;
}
