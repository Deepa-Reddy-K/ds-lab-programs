#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int ssn, sal; long int phno; char name[26], desg[20];
    struct node *prev, *next;
}node;
node *first = NULL;
node* read(node *temp) {
    printf("Enter Name        : ");
    scanf("%s", temp->name);
    printf("Enter SSN         : ");
    scanf("%d", &temp->ssn);
    printf("Enter Designation : ");
    scanf("%s", temp->desg);
    printf("Enter Salary      : ");
    scanf("%d", &temp->sal);
    printf("Enter Ph.No.      : ");
    scanf("%ld", &temp->phno);
    return temp;
}
void print(node *temp) {
    printf("\n");
    printf("Name        : %s\n", temp->name);
    printf("SSN         : %d\n",temp->ssn);
    printf("Designation : %s\n", temp->desg);
    printf("Salary      : %d\n", temp->sal);
    printf("Ph.No.      : %ld\n", temp->phno);
}
void insert_front() {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp = read(temp);
    if(first==NULL) { first = temp; first->prev = NULL; first->next = NULL; }
    else {
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}
void insert_end() {
    node *temp, *cur;
    temp = (node*)malloc(sizeof(node));
    temp = read(temp);
    if(first==NULL) { first = temp; first->prev = NULL; first->next = NULL; }
    else {
        cur = first;
        while(cur->next!=NULL)
            cur = cur->next;
        cur->next = temp;
        temp->prev = cur;
        temp->next = NULL;
    }
}
void delete_front() {
    node *temp = first;
    if(first==NULL) printf("List Empty\n"); return;
    first = first->next;
    first->prev = NULL;
    printf("-----NODE DELETED-----\n");
    print(temp);
    free(temp);
}
void delete_end() {
    node *temp, *cur = first;
    if(first==NULL) printf("List Empty\n"); return;
    while(cur->next!=NULL)
        cur = cur->next;
    temp = cur;
    cur = temp->prev;
    cur->next = NULL;
    printf("-----NODE DELETED-----\n");
    print(temp);
    free(temp);
}
void display() {
    int count = 0; node *cur = first;
    if(first==NULL) printf("List Empty\n");
    while(cur!=NULL){
        print(cur);
        cur = cur->next;
        count++;
    }
    printf("No. of nodes : %d\n", count);
}
void create() {
    int n, i;
    first=NULL;
    printf("Enter the no of employees : ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
        insert_end();
}
void deq() {
    int choice;
    while(1) {
        printf("-----DE-QUEUE MENU-----\n");
        printf("1. Insert Front\n2. Delete Front\n3. Insert End\n4. Delete End\n5. Display\n6. Return to main prog.\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert_front(); break;
            case 2: delete_front(); break;
            case 3: insert_end(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: return;
        }
    }
}
void main() {
    int choice;
    while(1) {
        printf("-----MENU-----\n");
        printf("1. Create new list\n2. Insert Front\n3. Delete Front\n4. Insert End\n5. Delete End\n6. Display\n7. Use as DE-Queue\n8. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create(); break;
            case 2: insert_front(); break;
            case 3: delete_front(); break;
            case 4: insert_end(); break;
            case 5: delete_end(); break;
            case 6: display(); break;
            case 7: deq(); break;
            case 8: return;
        }
    }
}