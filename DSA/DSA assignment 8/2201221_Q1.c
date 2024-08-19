#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct node *root, int *array, int *index)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, array, index);
    array[*index] = root->data;
    (*index)++;
    inorderTraversal(root->right, array, index);
}

struct node *buildMinHeap(int *array, int n)
{
    struct node **nodes = (struct node **)malloc(n * sizeof(struct node *));
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(array[i]);

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }

    return nodes[0];
}

void printTree(struct node *root, int space)
{
    if (root == NULL || space < 0)
    {
        return;
    }

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("\n");

    printTree(root->left, space);
}

int main()
{
    int n;
    printf("Enter the number of elements in the tree: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    struct node *bstRoot = NULL;
    bstRoot = createNode(a[0]);
    for (int i = 1; i < n; i++)
    {
        struct node *node = createNode(a[i]);
        struct node *current = bstRoot;
        struct node *parent = NULL;
        while (current != NULL)
        {
            parent = current;
            if (node->data <= current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (node->data <= parent->data)
            parent->left = node;
        else
            parent->right = node;
    }

    printf("\nThe binary search tree is:\n");
    printTree(bstRoot, 0);

    int heapArray[n];
    int index = 0;
    inorderTraversal(bstRoot, heapArray, &index);

    struct node *minHeapRoot = buildMinHeap(heapArray, n);

    printf("\nThe min heap is:\n");
    printTree(minHeapRoot, 0);

    return 0;
}
