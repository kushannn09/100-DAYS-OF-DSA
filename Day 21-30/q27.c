/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL, *temp, *newNode;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if(head1 == NULL)
            head1 = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if(head2 == NULL)
            head2 = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    while(head1 != NULL) {
        temp = head2;
        while(temp != NULL) {
            if(head1->data == temp->data) {
                printf("%d", head1->data);
                return 0;
            }
            temp = temp->next;
        }
        head1 = head1->next;
    }
    printf("No Intersection");
    return 0;
}
