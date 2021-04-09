#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int coeff, x, y, z;
    struct node *link;
} node;
int n;
node *attach(node *new, node *last)//attach new node after last node and return the current last node(i.e., new)
{
    new->link = last->link;
    last->link = new;
    return new;
}
node *read(node *head)//read n terms of a polynomial
{
    node *temp;
    int i;
    printf("Enter the no. of terms : ");
    scanf("%d", &n);
    printf("Enter the values for coeff, xexp ,yexp and zexp:\n");
    for (i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        scanf("%d%d%d%d", &temp->coeff, &temp->x, &temp->y, &temp->z);
        head = attach(temp, head);
    }
    return head->link;
}
node *create(int coeff, int x, int y, int z)//create a node with coeff, x, y and z exp and return
{
    node *temp = (node *)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->x = x;
    temp->y = y;
    temp->z = z;
}
void evaluate(node *head)//evaluate a polynomial using xval, yval and zval
{
    node *temp = head->link;
    int res = 0, xval, yval, zval;
    printf("Enter the values of x, y and z : ");
    scanf("%d%d%d", &xval, &yval, &zval);
    while (temp != head)
    {
        res = res + temp->coeff * pow(xval, temp->x) * pow(yval, temp->y) * pow(zval, temp->z);
        temp = temp->link;
    }
    printf("Result : %d\n", res);
}
void display(node *head)//display the list
{
    node *temp = head->link;
    while (temp != head)
    {
        if (temp->coeff == 0)
        {
            temp = temp->link;
            continue;
        }
        if (temp->coeff > 0)
            printf(" +");
        if (temp->coeff < 0)
            printf(" ");
        printf("%d(x^%d)(y^%d)(z^%d)", temp->coeff, temp->x, temp->y, temp->z);
        temp = temp->link;
    }
    printf("\n");
}
node *add(node *head1, node *head2)//add two polynomials using compare()
{
    node *a, *b, *res, *rear, *new;
    int comp;
    a = head1->link;//one and two are header nodes hence a=one->link and b=two->link
    b = head2->link;
    res = (node *)malloc(sizeof(node));
    res->link = res;
    rear = res;//rear stores the last node in the resulting polynomial, as after comparing terms they are attached to the end of res
    while (a != head1 && b != head2)
    {
        if (a->x == b->x && a->y == b->y && a->z && b->z)//0 if all exponents are same in both polynomials
            comp = 0;
        if (a->x > b->x)//1 if one or more exponents(x, y or z) of first polynomial is greater
            comp = 1;
        else if (a->x == b->x && a->y > b->y)
            comp = 1;
        else if (a->x == b->x && a->y == b->y && a->z > b->z)
            comp = 1;
        else//-1 otherwise
            comp = -1;

        switch (comp)
        {
        case 0:
            new = create(a->coeff + b->coeff, a->x, a->y, a->z);//Both terms of first and second polynomial have same exponents(add coeffs)
            rear = attach(new, rear);
            a = a->link;
            b = b->link;
            break;
        case 1:
            new = create(a->coeff, a->x, a->y, a->z);//term of first polynomial has greater exponents

            rear = attach(new, rear);
            a = a->link;
            break;
        case -1:
            new = create(b->coeff, b->x, b->y, b->z);//term of second polynomial has greater exponents
            rear = attach(new, rear);
            b = b->link;
            break;
        }
    }
    while (a != head1)//remaining terms in one are attached to res
    {
        new = create(a->coeff, a->x, a->y, a->z);
        rear = attach(new, rear);
        a = a->link;
    }
    while (b != head1)//remaining terms in two are attached to res
    {
        new = create(b->coeff, b->x, b->y, b->z);
        rear = attach(new, rear);
        b = b->link;
    }
    return res;
}
void main()
{
    node *head1, *head2;
    int choice;
    head1 = (node *)malloc(sizeof(node));
    head1->link = head1;
    head2 = (node *)malloc(sizeof(node));
    head2->link = head2;
    while (1)
    {
        printf("\n-----MENU-----\n");
        printf("1. Represent and Evaluate\n2. Add 2 polynomials\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head1 = read(head1);
            display(head1);
            evaluate(head1);
            break;
        case 2:
            printf("FOR 1st POLY\n");
            head1 = read(head1);
            printf("FOR 2nd POLY\n");
            head2 = read(head2);
            display(add(head1, head2));//add one and two and display result

            break;
        case 3:
            return;
        }
    }
}