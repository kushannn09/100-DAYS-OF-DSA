/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.*/
#include<stdio.h>
int main()
{
    int queue[100];
    int front = 0, rear = -1;
    int n, m, i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&queue[i]);
    }
    rear = n - 1;
    scanf("%d",&m);
    front = (front + m) % n;
    for(i = 0; i < n; i++)
    {
        printf("%d ", queue[(front + i) % n]);
    }
    return 0;
}
