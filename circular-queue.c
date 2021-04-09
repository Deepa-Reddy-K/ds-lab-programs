#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX], f=-1, r=-1, count = 0;
void insert() {
    if(count==MAX){ printf("QUEUE Full\n"); return; }
    r = (r+1)%MAX;
    printf("Enter the item : ");
    scanf("%d", &a[r]);
    count++;
    printf("Inserted : %d\n", a[r]);
}
void delete() {
    if(count==0){ printf("QUEUE Empty\n"); return; }
    f = (f+1)%MAX;
    count--;
    printf("Deleted : %d\n", a[f]);
}
void display() {
    int i=f;
    if(count==0){ printf("QUEUE Empty\n"); return; }
    while(i!=r) {
        i = (i+1)%MAX;
        printf("%d\t", a[i]);
    }
    printf("\n");
}
void main() {
    int choice;
    while(1) {
        printf("-----Circular Queue Menu-----\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return;
        }
    }
}