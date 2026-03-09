/*Implement a Priority Queue using an array. An element with smaller value has higher priority.*/
#include<stdio.h>
int main()
{
    int pq[100];
    int n,i,size=0;
    char op[10];
    int x,minIndex;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",op);
        if(op[0]=='i') 
        {
            scanf("%d",&x);
            pq[size]=x;
            size++;
        }
        else if(op[0]=='d') 
        {
            if(size==0)
            {
                printf("-1\n");
                continue;
            }
            minIndex=0;
            for(int j=1;j<size;j++)
            {
                if(pq[j]<pq[minIndex])
                    minIndex=j;
            }
            printf("%d\n",pq[minIndex]);
            for(int j=minIndex;j<size-1;j++)
            {
                pq[j]=pq[j+1];
            }
            size--;
        }
        else if(op[0]=='p') 
        {
            if(size==0)
            {
                printf("-1\n");
                continue;
            }
            minIndex=0;
            for(int j=1;j<size;j++)
            {
                if(pq[j]<pq[minIndex])
                    minIndex=j;
            }
            printf("%d\n",pq[minIndex]);
        }
    }
    return 0;
}
