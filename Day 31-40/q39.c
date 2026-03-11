/*Problem Statement:Implement a Min Heap using an array where the smallest element is always at the root.*/
#include<stdio.h>
int heap[100];
int size = 0;
void insert(int x)
{
    int i = size;
    heap[size++] = x;
    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        int t = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = t;

        i = (i-1)/2;
    }
}
int extractMin()
{
    if(size == 0)
        return -1;
    int min = heap[0];
    heap[0] = heap[size-1];
    size--;
    int i = 0;
    while(2*i+1 < size)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = left;
        if(right < size && heap[right] < heap[left])
            smallest = right;
        if(heap[i] <= heap[smallest])
            break;
        int t = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = t;
        i = smallest;
    }
    return min;
}
int peek()
{
    if(size == 0)
        return -1;
    return heap[0];
}
int main()
{
    insert(40);
    insert(10);
    insert(30);
    printf("%d\n", peek());
    printf("%d\n", extractMin());
    printf("%d\n", peek());
    return 0;
}
