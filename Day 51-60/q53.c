/*Problem Statement: Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = newNode(arr[0]);
    struct TreeNode** q = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    q[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct TreeNode* curr = q[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    free(q);
    return root;
}
typedef struct {
    int row, val, col;
} Node;
int cmp(const void* a, const void* b) {
    Node* x = (Node*)a;
    Node* y = (Node*)b;
    if (x->col != y->col) return x->col - y->col;
    if (x->row != y->row) return x->row - y->row;
    return x->val - y->val;
}
void verticalOrder(struct TreeNode* root) {
    if (!root) return;
    Node nodes[1000];
    int idx = 0;
    struct TreeNode* q[1000];
    int cols[1000], rows[1000];
    int front = 0, rear = 0;
    q[rear] = root;
    cols[rear] = 100;
    rows[rear] = 0;
    rear++;
    while (front < rear) {
        struct TreeNode* curr = q[front];
        int c = cols[front];
        int r = rows[front];
        front++;
        nodes[idx].val = curr->val;
        nodes[idx].row = r;
        nodes[idx].col = c;
        idx++;
        if (curr->left) {
            q[rear] = curr->left;
            cols[rear] = c - 1;
            rows[rear] = r + 1;
            rear++;
        }
        if (curr->right) {
            q[rear] = curr->right;
            cols[rear] = c + 1;
            rows[rear] = r + 1;
            rear++;
        }
    }
    qsort(nodes, idx, sizeof(Node), cmp);
    int i = 0;
    while (i < idx) {
        int j = i;
        while (j < idx && nodes[j].col == nodes[i].col) {
            printf("%d", nodes[j].val);
            j++;
            if (j < idx && nodes[j].col == nodes[i].col) printf(" ");
        }
        printf("\n");
        i = j;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root);
    free(arr);
    return 0;
}
