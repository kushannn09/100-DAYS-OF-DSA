// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
// Books must be allocated in contiguous order.
#include <stdio.h>

int isPossible(int arr[], int n, int m, int mid) {
    int students = 1, sum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) return 0;

        if(sum + arr[i] > mid) {
            students++;
            sum = arr[i];
            if(students > m) return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}
int findPages(int arr[], int n, int m) {
    if(m > n) return -1;

    int low = 0, high = 0, ans = -1;

    for(int i = 0; i < n; i++) {
        high += arr[i];
        if(arr[i] > low) low = arr[i];
    }
    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", findPages(arr, n, m));
    return 0;
}
