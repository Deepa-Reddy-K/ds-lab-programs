#include<stdio.h>
#include<ctype.h>
#include<math.h>
float stack[50]; int top = -1; char post[50];
void push(float item) { stack[++top] = item; }
float pop() { return stack[top--]; }
float operation(float op2, float op1, char op) {
    switch(op) {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '%': return (int)op1%(int)op2;
        case '^': return pow((int)op2, (int)op1);
    }
}
void eval() {
    int i;
    for(i=0; post[i]!='\0'; i++)
    {
        if(isdigit(post[i])) push(post[i] - '0');
        else {
            push(operation(pop(), pop(), post[i]));
        }
    }
    printf("Result = %.2f", pop());
}
void main() {
    printf("Enter the postfix expression for single digit operands : ");
    scanf("%s", post);
    eval();
}