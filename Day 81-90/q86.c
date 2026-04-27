/*Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.*/
#include <stdio.h>
int sqrtBinary(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid == n)
            return mid;

        if ((long long)mid * mid < n) {
            ans = mid;      
            low = mid + 1;  
        } else {
            high = mid - 1; 
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);

    printf("%d", sqrtBinary(n));
    return 0;
}
