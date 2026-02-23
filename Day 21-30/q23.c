/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    int n, m, i;
    struct node *l1 = NULL, *l2 = NULL, *temp, *newnode;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = l1;
        l1 = newnode;
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = l2;
        l2 = newnode;
    }
    struct node dummy;
    temp = &dummy;
    dummy.next = NULL;
    while(l1 && l2) {
        if(l1->data < l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1) temp->next = l1;
    else temp->next = l2;
    temp = dummy.next;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
