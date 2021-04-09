#include<stdio.h>
char infix[100], post[100], stack[20]; int top = -1;
void push(char item) { stack[++top] = item; }
char pop() { return stack[top--]; }
int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '/':
        case '%':
        case '*': return 2;
        case '+':
        case '-': return 1;
        case '(': return 0;
        case '#': return -1;
    }
}
void inpo() {
    int i, p=0; char item;
    push('#');
    for(i=0; infix[i]!='\0'; i++) {
        switch(infix[i]) {
            case '(': push('('); break;
            case ')': item = pop();
                      while(item!='\0') {
                          post[p++] = item;
                          item = pop();
                      }
                      break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%': while(precedence(stack[top]) >= precedence(infix[i]))
                        post[p++] = pop();
                      push(infix[i]); break;
            case '^': while(precedence(stack[top]) > precedence(infix[i]))
                        post[p++] = pop();
                      push(infix[i]); break;
            default: post[p++] = infix[i]; break;
        }
    }
    while(top>0) {
        post[p++] = pop();
        if(post[p-1]=='(') p--;
    }
    post[--p] = '\0';
}
void main() {
    printf("Enter the Infix Expression : ");
    scanf("%s", infix);
    inpo();
    printf("Postfix : %s", post);
}