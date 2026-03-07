/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.*/
#include<stdio.h>
int queue[100];
int front = -1;
int rear = -1;
int main() {
    int n, i, x;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&x);
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
    }
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    return 0;
}
