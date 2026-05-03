// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;
void insertSorted(Node** head, float val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL || (*head)->val >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next && curr->next->val < val)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
}
int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node** buckets = (Node**)calloc(n, sizeof(Node*));

    for (int i = 0; i < n; i++) {
        int idx = arr[i] * n;
        insertSorted(&buckets[idx], arr[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr) {
            arr[k++] = curr->val;
            curr = curr->next;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    return 0;
}
