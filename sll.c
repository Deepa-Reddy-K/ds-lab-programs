#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int usn, sem;
    char name[26], branch[4];
    long int phno;
    struct node *link;
}node;
node *first = NULL;
node* read(node *temp) {
    printf("Enter USN : ");
    scanf("%d", &temp->usn);
    printf("Enter Name : ");
    scanf("%s", temp->name);
    printf("Enter Sem : ");
    scanf("%d", &temp->sem);
    printf("Enter branch : ");
    scanf("%s", temp->branch);
    printf("Enter Phone No. : ");
    scanf("%ld", &temp->phno);
    return temp;
}
void print(node *temp) {
    printf("Name    : %s\n", temp->name);
    printf("USN     : %d\n", temp->usn);
    printf("Sem     : %d\n", temp->sem);
    printf("Branch  : %s\n", temp->branch);
    printf("Ph. No. : %ld\n", temp->phno);
    printf("\n");
}
void insert_front() {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp = read(temp);
    temp->link = first;
    first = temp;
}
void insert_end() {
    node *temp, *cur=first;
    temp = (node*)malloc(sizeof(node));
    temp = read(temp);
    temp->link = NULL;
    if(first!=NULL) {
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=temp;
    }
    else
        first = temp;
}
void delete_front() {
    node *temp = first;
    if(first!=NULL) {
        first = first->link;
        printf("-----Node Deleted!-----\n");
        print(temp);
        free(temp);
    }
    else
        printf("List Empty\n");
}
void delete_end() {
    node *prev=NULL, *cur=first;
    if(first!=NULL) {
        while(1){
            if(cur->link==NULL) break;
            else{
                prev = cur; cur = cur->link;
            }
        }
        printf("-----Node Deleted!-----\n");
        print(cur);
        free(cur);
        prev->link = NULL;
    }
    else
        printf("List Empty\n");
}
void create() {
    int n, i; first=NULL;
    printf("Enter the no of students : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf("Enter the Info for student %d\n", i);
        insert_front();
    }
}
void display() {
    node *cur = first; int count = 0;
    if(first==NULL) printf("List Empty.\n");
    else {
        while(cur!=NULL) {
            print(cur);
            cur = cur->link;
            count++;
        }
        printf("No. of Nodes : %d\n", count);
    }
}
void stack() {
    int choice;
    while(1) {
        printf("-----Stack Menu-----\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Return to main prog\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert_front(); break;
            case 2: delete_front(); break;
            case 3: display(); break;
            case 4: return;
        }
    }
}
void queue() {
    int choice;
    while(1) {
        printf("-----Queue Menu-----\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Return to main prog\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert_end(); break;
            case 2: delete_front(); break;
            case 3: display(); break;
            case 4: return;
        }
    }
}
void main() {
    int choice;
    while(1) {
        printf("-----Menu-----\n");
        printf("1. Create a new List\n2. Display Status\n3. Insert at Front\n4. Insert at End\n5. Delete at Front\n6. Delete at End\n7. Use as Stack\n8. Use as Queue\n9. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert_front(); break;
            case 4: insert_end(); break;
            case 5: delete_front(); break;
            case 6: delete_end(); break;
            case 7: stack(); break;
            case 8: queue(); break;
            case 9: return;
        }
    }
}