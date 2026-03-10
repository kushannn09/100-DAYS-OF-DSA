/*Problem: Deque (Double-Ended Queue)
A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.*/
#include<stdio.h>
int main()
{
    int dq[100];
    int front=-1, rear=-1;
    int i;
    if(front==-1)
    {
        front=0;
        rear=0;
        dq[rear]=10;
    }
    else
    {
        rear++;
        dq[rear]=10;
    }
    rear++;
    dq[rear]=20;
    if(front==0)
    {
        for(i=rear;i>=front;i--)
            dq[i+1]=dq[i];
        dq[front]=5;
        rear++;
    }
    rear--;
    front++;
    printf("Deque elements:\n");
    for(i=front;i<=rear;i++)
        printf("%d ",dq[i]);
    printf("\nFront element: %d",dq[front]);
    printf("\nRear element: %d",dq[rear]);
    printf("\nSize: %d",rear-front+1);
    return 0;
}
