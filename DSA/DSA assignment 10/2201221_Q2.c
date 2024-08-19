#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root, int value)
{
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

node* createBST(int n)
{
    int value;
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);
        root = insert(root, value);
    }
    return root;
}

int inorder(node* root, int* a, int i)
{
    if (root == NULL)
    {
        return i;
    }
    i = inorder(root->left, a, i);
    a[i] = root->data;
    i++;
    i = inorder(root->right, a, i);
    return i;
}

int compareTrees(node* root1, node* root2, int n1, int n2)
{
    int inorder1[n1];
    int inorder2[n2];
    int size1 = inorder(root1, inorder1, 0);
    int size2 = inorder(root2, inorder2, 0);
    if (size1 != size2)
    {
        free(inorder1);
        free(inorder2);
        return 0;
    }
    for (int i = 0; i < size1; i++)
    {
        if (inorder1[i] != inorder2[i])
        {
            free(inorder1);
            free(inorder2);
            return 0;
        }
    }
    free(inorder1);
    free(inorder2);
    return 1;
}

int main()
{
    node* root1;
    node* root2;
    printf("Number of elements (tree 1): ");
    int n1, n2;
    scanf("%d", &n1);
    printf("Number of elements (tree 2): ");
    scanf("%d", &n2);
    printf("Tree 1\n");
    root1 = createBST(n1);
    printf("Tree 2\n");
    root2 = createBST(n2);
    int check = compareTrees(root1, root2, n1, n2);
    if (check)
    {
        printf("\nTRUE\n");
    } else
    {
        printf("\nFALSE\n");
    }
    return 0;
}
