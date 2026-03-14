/*Problem Statement: Given a queue of integers, reverse the queue using a stack.*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int queue[100], stack[100];
    int top = -1;

    printf("Enter queue elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    for(int i = 0; i < n; i++)
    {
        stack[++top] = queue[i];
    }
    printf("Reversed Queue:\n");
    while(top != -1)
    {
        printf("%d ", stack[top]);
        top--;
    }
    return 0;
}
