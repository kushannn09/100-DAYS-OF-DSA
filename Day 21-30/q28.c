/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, i, value;
    struct Node *head = NULL, *temp, *newNode;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        if(head == NULL) {
            head = newNode;
            newNode->next = head;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }
    if(head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }
    return 0;
}
