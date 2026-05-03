// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;
int cmp(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}
int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(Interval), cmp);

    Interval* res = (Interval*)malloc(n * sizeof(Interval));
    int k = 0;

    res[k] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= res[k].end) {
            if (arr[i].end > res[k].end)
                res[k].end = arr[i].end;
        } else {
            k++;
            res[k] = arr[i];
        }
    }
    for (int i = 0; i <= k; i++) {
        printf("[%d,%d] ", res[i].start, res[i].end);
    }
    free(res);
    return 0;
}
