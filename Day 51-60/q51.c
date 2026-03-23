/*Problem Statement: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    
    if (n1 < root->val && n2 < root->val) {
        return findLCA(root->left, n1, n2);
    }
    
    if (n1 > root->val && n2 > root->val) {
        return findLCA(root->right, n1, n2);
    }
    
    return root;
}
int main() {
    int N;
    scanf("%d", &N); 
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }    
    int p, q;
    scanf("%d %d", &p, &q);    
    Node* lca = findLCA(root, p, q);  
    if (lca != NULL) {
        printf("%d\n", lca->val);
    } else {
        printf("-1\n");
    }
    return 0;
}
