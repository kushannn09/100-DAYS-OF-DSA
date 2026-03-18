/*Problem: Level Order Traversal
Implement the solution for this problem.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
#define MAX 2005
struct TreeNode* q[MAX];
int front = 0, rear = 0;
void levelOrder(struct TreeNode* root) {
    if (!root) return;
    q[rear++] = root;
    
    while (front < rear) {
        int size = rear - front;
        printf("[ ");
        
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[front++];
            printf("%d ", node->val);
            
            if (node->left)  q[rear++] = node->left;
            if (node->right) q[rear++] = node->right;
        }
        printf("]\n");
    }
}
int main() {
    struct TreeNode n1 = {1,NULL,NULL}, n2 = {2,NULL,NULL}, n3 = {3,NULL,NULL};
    n1.left = &n2; n1.right = &n3;
    levelOrder(&n1);
    return 0;
}
