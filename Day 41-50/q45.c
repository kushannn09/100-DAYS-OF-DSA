/*Problem Statement: Find the height (maximum depth) of a given binary tree.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = q[front++];
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
    return root;
}
int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[1005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    printf("%d\n", height(root));
    return 0;
}
