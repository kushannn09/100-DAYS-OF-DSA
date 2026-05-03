// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Node;
int cmp(const void* a, const void* b) {
    return ((Node*)a)->val - ((Node*)b)->val;
}
void update(int BIT[], int n, int i) {
    while (i <= n) {
        BIT[i] += 1;
        i += i & -i;
    }
}
int query(int BIT[], int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= i & -i;
    }
    return sum;
}
int main() {
    int arr[] = {5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* temp = (Node*)malloc(n * sizeof(Node));

    for (int i = 0; i < n; i++) {
        temp[i].val = arr[i];
        temp[i].idx = i;
    }
    qsort(temp, n, sizeof(Node), cmp);

    int* rank = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        rank[temp[i].idx] = i + 1;
    }
    int* BIT = (int*)calloc(n + 1, sizeof(int));
    int* result = (int*)calloc(n, sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        result[i] = query(BIT, rank[i] - 1);
        update(BIT, n, rank[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    free(temp);
    free(rank);
    free(BIT);
    free(result);

    return 0;
}
