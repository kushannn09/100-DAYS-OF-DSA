// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;
int cmp(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}
void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}
void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}
void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(&heap[smallest], &heap[index]);
        heapifyDown(heap, size, smallest);
    }
}
int main() {
    Interval arr[] = {{0,30}, {5,10}, {15,20}};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(Interval), cmp);

    int* heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    heap[size++] = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (heap[0] <= arr[i].start) {
            heap[0] = arr[i].end;
            heapifyDown(heap, size, 0);
        } else {
            heap[size] = arr[i].end;
            heapifyUp(heap, size);
            size++;
        }
    }
    printf("%d", size);
    free(heap);
    return 0;
}
