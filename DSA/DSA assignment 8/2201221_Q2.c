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

void maxHeapify(struct node *root)
{
    if (root == NULL)
        return;

    struct node *largest = root;
    struct node *left = root->left;
    struct node *right = root->right;

    if (left != NULL && left->data > largest->data)
        largest = left;

    if (right != NULL && right->data > largest->data)
        largest = right;

    if (largest != root)
    {
        int temp = root->data;
        root->data = largest->data;
        largest->data = temp;

        maxHeapify(largest);
    }
}

struct node *insertIntoMaxHeap(struct node *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
        return root;
    }

    if (value > root->data)
    {
        int temp = root->data;
        root->data = value;
        value = temp;
    }

    if (root->left == NULL)
        root->left = insertIntoMaxHeap(root->left, value);
    else if (root->right == NULL)
        root->right = insertIntoMaxHeap(root->right, value);
    else if (root->left->data < root->right->data)
        root->left = insertIntoMaxHeap(root->left, value);
    else
        root->right = insertIntoMaxHeap(root->right, value);

    maxHeapify(root);
    return root;
}

/*struct node* deleteElement(struct node* root, int value) {
    if (root == NULL)
        return root;

    if (root -> data == value) {
        free(root);
        return NULL;
    }

    struct node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct node *temp = queue[++front];

        if (temp->left != NULL) {
            if (temp->left->data == value) {
                free(temp->left);
                temp->left = NULL;
                break;
            } else {
                queue[++rear] = temp->left;
            }
        }

        if (temp->right != NULL) {
            if (temp->right->data == value) {
                free(temp->right);
                temp->right = NULL;
                break;
            } else {
                queue[++rear] = temp->right;
            }
        }
    }

    maxHeapify(root);
    return root;
}*/

void printTree(struct node *root, int space)
{
    if (root == NULL || space < 0)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    for (int i = 5; i < space; i++)
        printf(" ");
    printf("\n");

    printTree(root->left, space);
}

int main()
{
    int n;
    printf("Enter the number of elements in the max heap: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insertIntoMaxHeap(root, arr[i]);
    }

    printf("\nThe max heap is:\n");
    printTree(root, 0);

    int option, value, index;
    do
    {
        printf("\nOperations:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display max heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                {
                    printf("Enter the element you want to insert: ");
                    scanf("%d", &value);
                    root = insertIntoMaxHeap(root, value);
                    printf("Display max heap after insertion:\n");
                    printTree(root, 0);
                    break;
                }
            case 2:
                {
                    printf("Enter the index you want to delete element from: ");
                    scanf("%d", &index);
                    root = deleteElement(root, index);
                    printf("Display max heap after deletion:\n");
                    printTree(root, 0);
                    break;
                }
            case 3:
                {
                    printf("Display max heap:\n");
                    printTree(root, 0);
                    break;
                }
            case 4:
                {
                    printf("Exiting...\n");
                    exit(0);
                    break;
                }
            default:
                {
                    printf("Invalid choice!\n");
                    break;
                }
        }
    } while (option != 4);

    return 0;
}
