/*Problem: Count Leaf Nodes Implement the solution for this problem.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create(int data) {
    if (data == -1) return NULL;
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
struct Node* build(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = create(arr[0]);
    struct Node* q[n];
    int f = 0, r = 0, i = 1;
    q[r++] = root;

    while (i < n) {
        struct Node* temp = q[f++];
        if (arr[i] != -1) {
            temp->left = create(arr[i]);
            q[r++] = temp->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            temp->right = create(arr[i]);
            q[r++] = temp->right;
        }
        i++;
    }
    return root;
}
int count(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return count(root->left) + count(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, n);
    printf("%d", count(root));
    return 0;
}
