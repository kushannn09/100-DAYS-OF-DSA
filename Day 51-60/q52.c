/*Problem Statement: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* buildTree(int a[], int n) {
    if (n == 0 || a[0] == -1) return NULL;
    struct TreeNode* root = newNode(a[0]);
    struct TreeNode** q = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    q[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct TreeNode* curr = q[front++];
        if (i < n && a[i] != -1) {
            curr->left = newNode(a[i]);
            q[rear++] = curr->left;
        }
        i++;
        if (i < n && a[i] != -1) {
            curr->right = newNode(a[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    free(q);
    return root;
}
struct TreeNode* lca(struct TreeNode* root, int p, int q) {
    if (!root) return NULL;
    if (root->val == p || root->val == q) return root;
    struct TreeNode* left = lca(root->left, p, q);
    struct TreeNode* right = lca(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int N;
    scanf("%d", &N);
    int* a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    int p, q;
    scanf("%d %d", &p, &q);
    
    struct TreeNode* root = buildTree(a, N);
    struct TreeNode* ans = lca(root, p, q);
    printf("%d\n", ans ? ans->val : -1);
  
    free(a);
    return 0;
}
