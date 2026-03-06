/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
    int data;
    struct node* next;
};
struct node* top = NULL;
void push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}
int pop(){
    int x;
    struct node* temp = top;
    x = top->data;
    top = top->next;
    free(temp);
    return x;
}
int main(){
    char exp[] = "231*+9-";
    int i=0,a,b;
    while(exp[i] != '\0'){
        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else{
            b = pop();
            a = pop();
            if(exp[i]=='+') push(a+b);
            if(exp[i]=='-') push(a-b);
            if(exp[i]=='*') push(a*b);
            if(exp[i]=='/') push(a/b);
        }
        i++;
    }
    printf("%d", pop());
}
