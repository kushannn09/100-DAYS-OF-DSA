/*Problem: Count Nodes in Linked List*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    int n, i, count = 0;
    scanf("%d", &n);
    struct node *head = NULL, *temp, *newnode;
    for(i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
    }
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("%d", count);
    return 0;
}
