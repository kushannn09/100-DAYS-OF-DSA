/*Problem: Convert an infix expression to postfix notation using stack.*/
#include <stdio.h>
char stack[50];
int top = -1;
void push(char x){
    stack[++top] = x;
}
char pop(){
    return stack[top--];
}
int main(){
    char exp[] = "A+B*C";
    int i = 0;
    while(exp[i]){
        if((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z'))
            printf("%c", exp[i]);
        else
            push(exp[i]);
        i++;
    }
    while(top != -1)
        printf("%c", pop());
    return 0;
}
