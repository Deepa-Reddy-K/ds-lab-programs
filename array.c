#include<stdio.h>
int n, a[50];
void create() {
    int i;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    printf("Enter the elements :\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
}
void insert() {
    int pos, i, item;
    printf("Enter the item : ");
    scanf("%d", &item);
    printf("Enter the position (1 to %d) : ", n+1);
    scanf("%d", &pos);
    pos = pos - 1;
    if(pos<0 || pos>n)
        printf("Invalid Position.\n");
    else {
        if(pos==n) {
            a[n]=item; printf("%d is inserted\n", a[n]); n++;
        }
        else{
            for(i=n-1; i>=pos; i--)
                a[i+1]=a[i];
            a[pos]=item;
            printf("%d is inserted\n", a[pos]);
            n++;
        }
    }
}
void delete() {
    int pos; int i;
    printf("Enter the position (1 to %d) : ", n);
    scanf("%d", &pos);
    pos = pos - 1;
    if(pos<0 || pos>n-1)
        printf("Invalid Position.\n");
    else {
        if(pos==n) {
            printf("%d is deleted\n", a[n]);n--;
        }
        else {
            printf("%d is deleted\n", a[pos]);
            for(i=pos; i<n; i++)
                a[i]=a[i+1];
            n--;
        }
    }
}
void display() {
    int i;
    printf("Array elements : \n");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
void main() {
    int choice;
    while(1) {
        printf("1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: delete(); break;
            case 4: display(); break;
            case 5: return;
        }
    }
}