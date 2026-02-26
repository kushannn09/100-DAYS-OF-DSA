/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
int main() {
    int n, i;
    scanf("%d", &n);
    struct node *head = NULL, *temp = NULL, *newnode;
    for(i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = temp;
        if(head == NULL)
            head = newnode;
        else
            temp->next = newnode;
        temp = newnode;
    }
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
