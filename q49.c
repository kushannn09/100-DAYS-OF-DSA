/*Problem: BST Insert Implement the solution for this problem.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
struct node* create(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    int n, x;
    struct node* root = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    inorder(root);
    return 0;
}
