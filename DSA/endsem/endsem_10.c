#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node * left;
    struct node * right;
}node;

node * createNode(int value)
{
    node * newnode = (node *)malloc(sizeof(node));
    newnode -> data = value;
    newnode -> right = NULL;
    newnode -> left = NULL;
    return newnode;
}

node * insertDLL(node * head, int value)
{
    node * temp = NULL;
    if (head == NULL)
    {
        head = createNode(value);
    }
    else
    {
        node * p = head;
        while (p -> right != NULL)
        {
            p = p -> right;    
        }
        temp = p;
        p -> right = createNode(value);
        p = p -> right;
        p -> left = temp;
    }
    return head;
}

node * findTAILS(node * head)
{
    node * p;
    p = head;
    while (p -> right != NULL)
    {
        p = p -> right;
    }
    return p;
}

void displayF(node * head)
{
    node * p;
    p = head;
    while (p != NULL)
    {
        printf("%d -> ", p -> data);
        p = p -> right;
    }
    printf("NULL\n");
}

void displayR(node * tail)
{
    node * p;
    p = tail;
    while (p != NULL)
    {
        printf("%d -> ", p -> data);
        p = p -> left;
    }
    printf("NULL\n");
}

void sort(node * head)
{
    node * p;
    p = head;
    node * p1;
    while (p -> right != NULL)
    {
        p1 = p -> right;
        while (p1 != NULL)
        {
            if(p -> data > p1 -> data)
            {
                int temp = p -> data;
                p -> data = p1 -> data;
                p1 -> data = temp;
            }
            p1 = p1 -> right;
        }
        p = p -> right;
    }
}

node * merge(node * head1, node* head2, node *tail1, node * tail2)
{
    tail1 -> right = head2;
    head2 -> left = tail1;
    node * head = head1;
    return head;
}

int main()
{
    node * head1 = NULL, * head2 = NULL;
    node * tail1, * tail2;
    int n1, n2;
    printf("enter the sizes of the 2 DLL's: ");
    scanf("%d %d", &n1, &n2);
    printf("LIST 1\n");
    for (int i = 0; i < n1; i++)
    {
        int value;
        printf("enter the data of node %d: ", i + 1);
        scanf("%d", &value);
        head1 = insertDLL(head1, value);
    }
    printf("LIST 2\n");
    for (int i = 0; i < n2; i++)
    {
        int value;
        printf("enter the data of node %d: ", i + 1);
        scanf("%d", &value);
        head2 = insertDLL(head2, value);
    }
    tail1 = findTAILS(head1);
    tail2 = findTAILS(head2);
    printf("LIST 1:\n");
    displayF(head1);
    displayR(tail1);
    printf("LIST 2:\n");
    displayF(head2);
    displayR(tail2);
    sort(head1);
    printf("LIST 1 (after sorting):\n");
    displayF(head1);
    displayR(tail1);
    sort(head2);
    printf("LIST 2 (after sorting):\n");
    displayF(head2);
    displayR(tail2);
    node * head = merge(head1, head2, tail1, tail2);
    node * tail = findTAILS(head);
    printf("merged LIST:\n");
    displayF(head);
    displayR(tail);
    sort(head);
    printf("merged LIST (sorted):\n");
    displayF(head);
    displayR(tail);
    return 0;
}