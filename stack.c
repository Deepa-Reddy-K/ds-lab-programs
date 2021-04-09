#include<stdio.h>
#define MAX 50
int s[MAX], top=-1;
void push(int item) { s[++top] = item; }
int pop() { return s[top--]; }
void check() {
    int n, num, flag = 1;
    printf("Enter a number to check for palindrome : ");
    scanf("%d", &num);
    n = num; top=-1;
    while(n!=0) {
        push(n%10);
        n/=10;
    }
    n = num;
    while(n!=0) {
        if(n%10 != pop()) flag--; break;
        n/=10;
    }
    if(flag==1)
        printf("It is palindrome.\n");
    else
        printf("It is not a palindrome.\n");
}
void display() {
    int i;
    for(i=top; i>=0; i--)
        printf("%d\t", s[i]);
    printf("\n");
}
void main() {
    int choice, item;
    while(1) {
        printf("1. Push\n2. Pop\n3. Check for Palindrome(Contents of stack will be lost and it will be reset)\n4. Display\n5. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the element : ");
                    scanf("%d", &item);
                    push(item); break;
            case 2: item = pop();
                    printf("%d is deleted\n", item); break;
            case 3: check(); break;
            case 4: display(); break;
            case 5: return;
        }
    }
}