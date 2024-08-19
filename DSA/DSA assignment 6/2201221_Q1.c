#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}node;

node *create()
{
    int x;
    node * newnode;
    printf("enter the data: ");
    scanf("%d", &x);
    newnode = (node *)malloc(sizeof(node));
    //enter -1 to terminate the recursion
    if (x == -1)
    {
        return 0;
    }
    newnode -> data = x;
    printf("left child of %d\n", x);
    newnode -> left = create();
    printf("right child of %d\n", x);
    newnode -> right = create();
    return newnode;
}

void preorder(node * root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d  ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(node * root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root -> left);
    printf("%d  ", root -> data);
    inorder(root -> right);
}

void postorder(node * root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d  ", root -> data);
}

int height(node * root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height(root -> left);
    int right_height = height(root -> right);
    return (left_height > right_height)? left_height + 1 : right_height + 1;
}

int main()
{
    node * root;
    root = create();
    printf("the tree in preorder is: ");
    preorder(root);
    printf("\nthe tree in inorder is: ");
    inorder(root);
    printf("\nthe tree in postorder is: ");
    postorder(root);
    int h = height(root);
    //here height starts from 1
    printf("\nthe height of the entered binary tree is %d", h);
}