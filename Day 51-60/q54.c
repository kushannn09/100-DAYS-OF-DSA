/*Problem Statement: Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    q[rear++] = root;
    int i = 1;
    while (i < n && front < rear) {
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
    free(q);
    return root;
}
void zigzag(struct Node* root) {
    if (!root) {
        printf("\n");
        return;
    }
    struct Node** q = (struct Node**)malloc(10000 * sizeof(struct Node*));
    int front = 0, rear = 0;
    q[rear++] = root;
    int ltr = 1;
    int first = 1;
    while (front < rear) {
        int size = rear - front;
        int* level = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            struct Node* node = q[front++];
            level[i] = node->val;
            if (node->left) q[rear++] = node->left;
            if (node->right) q[rear++] = node->right;
        }
        if (!ltr) {
            for (int i = size-1; i >= 0; i--) {
                if (!first) printf(" ");
                printf("%d", level[i]);
                first = 0;
            }
        } else {
            for (int i = 0; i < size; i++) {
                if (!first) printf(" ");
                printf("%d", level[i]);
                first = 0;
            }
        }
        free(level);
        ltr = !ltr;
    }
    free(q);
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    zigzag(root);
    free(arr);
    return 0;
}
