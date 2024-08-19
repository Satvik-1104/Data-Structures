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
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

node* createBST()
{
    int value;
    node* root = NULL;
    printf("enter -1 as data if you want to exit\n");
    while (1)
    {
        printf("Enter data: ");
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        root = insert(root, value);
    }
    return root;
}

int countElements(node* root)
{
    if (root == NULL) {
        return 0;
    }
    int count = 1;
    count += countElements(root->left);
    count += countElements(root->right);
    return count;
}

void inorder(node* root, int n, int a[], int* index)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, n, a, index);
    a[*index] = root->data;
    (*index)++;
    inorder(root->right, n, a, index);
}

int main()
{
    node* root = createBST();
    int size = countElements(root);
    int a[size];
    int index = 0;
    inorder(root, size, a, &index);
    printf("enter the range of numbers (k1, k2): ");
    int k1, k2;
    scanf("%d %d", &k1, &k2);
    for (int i = 0; i < size; i++)
    {
        if (k1 < k2)
        {
            if ((a[i] >= k1) && (a[i] <= k2))
        {
                printf("%d ", a[i]);
        }
        }
        else
        {
            if ((a[i] >= k2) && (a[i] <= k1))
        {
                printf("%d ", a[i]);
        }
        }
    }
    return 0;
}
