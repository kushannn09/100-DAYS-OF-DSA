/*Problem: Implement push and pop operations on a stack and verify stack operations.*/
#include <stdio.h>
int main() {
    int stack[100];
    int top = -1;
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int m = 2;
    for(int i = 0; i < n; i++) {
        stack[++top] = arr[i];
    }
    for(int i = 0; i < m; i++) {
        if(top != -1)
            top--;
    }
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    return 0;
}
