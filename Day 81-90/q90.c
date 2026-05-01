// Problem Statement: Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.
// Determine the minimum time required to paint all boards.
#include <stdio.h>
int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1, sum = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) return 0;
        if(sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            painters++;
            sum = arr[i];
        }
    }
    return painters <= k;
}
int painterPartition(int arr[], int n, int k) {
    int start = 0, end = 0, ans = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > start) start = arr[i];
        end += arr[i];
    }
    while(start <= end) {
        int mid = (start + end) / 2;
        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("%d", painterPartition(arr, n, k));
    return 0;
}
