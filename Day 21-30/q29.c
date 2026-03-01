/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int k = 2;
    struct Node *head = NULL, *temp = NULL, *newNode;
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    for(int i = 0; i < k; i++) {
        struct Node *prev = NULL;
        temp = head;
        while(temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        temp->next = head;
        head = temp;
    }
    temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
