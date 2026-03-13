/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;

    if(front==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("-1\n");
        return;
    }

    struct node *temp=front;
    printf("%d\n",front->data);
    front=front->next;
    free(temp);
}
int main()
{
    int n,x;
    char op[10];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(op[0]=='e')
        {
            scanf("%d",&x);
            enqueue(x);
        }
        else
        {
            dequeue();
        }
    }
    return 0;
}
