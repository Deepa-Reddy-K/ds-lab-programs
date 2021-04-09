#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int key;
    struct node *rchild, *lchild;
}node;
node *root = NULL;
void inorder(node *temp) {
    if(temp!=NULL) {
        inorder(temp->lchild);
        printf("%d\t", temp->key);
        inorder(temp->rchild);
    }
}
void preorder(node *temp) {
    if(temp!=NULL) {
        printf("%d\t", temp->key);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}
void postorder(node *temp) {
    if(temp!=NULL) {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d\t", temp->key);
    }
}
void add(int item) {
    node *temp,*cur,*prev;
    temp=(node*)malloc(sizeof(node));
    temp->key=item;
    temp->lchild=NULL;
    temp->rchild=NULL;
    if(root==NULL) root=temp;
    else {
        prev=NULL;
        cur=root;
        while(cur!=NULL) {
            prev=cur;
            if(item<cur->key)
                cur = cur->lchild;
            else cur->rchild;
        }
        if(item<prev->key) prev->lchild=temp;
        else prev->rchild=temp;
    }
}
void create() {
    int a,n,i;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++) {
        scanf("%d",&a);
        add(a);
    }
}
void search(int key) {
    node*cur=root;
    while(cur!=NULL) {
        if(key==cur->key) {
            printf("Found\n"); return;
        }
        else if(key<cur->key) cur=cur->lchild;
        else cur=cur->rchild;
    }
    printf("Not Found\n");
}
node* find_minimum(node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->lchild != NULL) // node with minimum value will have no left child
        return find_minimum(root->lchild); // left most element will be minimum
    return root;
}
node* delete(node *root, int key)
{
    node *temp;
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (key>root->key)
        root->rchild = delete(root->rchild, key);
    else if(key<root->key)
        root->lchild = delete(root->lchild, key);
    else
    {
        //No Children
        if(root->lchild==NULL && root->rchild==NULL)
        {
            free(root);
            return NULL;
        }
        //One Child
        else if(root->lchild==NULL || root->rchild==NULL)
        {
            if(root->lchild==NULL)
                temp = root->rchild;
            else
                temp = root->rchild;
            free(root);
            return temp;
        }
        //Two Children
        else
        {
            temp = find_minimum(root->rchild);
            root->key = temp->key;
            root->rchild = delete(root->rchild, temp->key);
        }
    }
    return root;
}
void main() {
    int choice, item;
    while(1) {
        printf("\n-----BST Menu-----\n");
        printf("1. Create a new BST\n2. Insert\n3. Delete\n4. Inorder\n5. Preorder\n6. Postorder\n7. Search\n8. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create(); break;
            case 2: printf("Enter the item to insert : ");
                    scanf("%d", &item);
                    add(item); break;
            case 3: printf("Enter the key value to delete : ");
                    scanf("%d", &item);
                    delete(root, item);
                    break;
            case 4: inorder(root); break;
            case 5: preorder(root); break;
            case 6: postorder(root); break;
            case 7: printf("Enter the item to search : ");
                    scanf("%d", &item);
                    search(item); break;
            case 8: return;
        }
    }
}