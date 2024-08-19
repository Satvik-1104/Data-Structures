#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}node;

node * create()
{
    int value;
    node * temp;
    printf("enter data: ");
    scanf("%d", &value);
    temp = (node *)malloc(sizeof(node));
    //enter -1 to terminate the recursion
    if(value == -1)
    {
        return NULL;
    }
    temp -> data = value;
    printf("left child of %d\n", temp -> data);
    temp -> left = create();
    printf("right child of %d\n", temp -> data);
    temp -> right = create();
    return temp;
}

int BSTcheck(node * root, int minVal, int maxVal)
{
    if (root == NULL)
    {
        return 1;
    }
    if (((root -> data) < minVal) || ((root -> data) > maxVal))
    {
        return 0;
    }
    return (BSTcheck(root -> left, minVal, (root -> data) - 1) && BSTcheck(root -> right, (root -> data) + 1, maxVal));
}

void isBST(node * root)
{
    int check = BSTcheck(root, INT_MIN, INT_MAX);
    if (check == 1)
    {
        printf("it is a binary search tree\n");
    }   
    else
    {
        printf("it is not a binary search tree\n");
    }
}

int main()
{
    node * root;
    root = create();
    isBST(root);
    return 0;
}