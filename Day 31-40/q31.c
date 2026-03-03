/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.*/
#include <stdio.h>
int main() {
    int stack[100];
    int top = -1;
    int n, type, value;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d", &value);
            top++;
            stack[top] = value;
        }
        else if(type == 2) {
            if(top == -1)
                printf("Stack Underflow\n");
            else {
                printf("%d\n", stack[top]);
                top--;
            }
        }
        else if(type == 3) {
            for(int j = top; j >= 0; j--)
                printf("%d ", stack[j]);
            printf("\n");
        }
    }
    return 0;
}
