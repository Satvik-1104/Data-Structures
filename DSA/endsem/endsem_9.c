#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * createNODE(int value)
{
    node * newnode = (node *)malloc(sizeof(node));
    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}

node * insert(node * head, int value)
{
    if (head == NULL)
    {
        head = createNODE(value);
    }
    else
    {
        node * p = head;
        while (p -> next != NULL)
        {
            p = p -> next;
        }
        p -> next = createNODE(value);
    }
    return head;
}

void displayLL(node * head)
{
    node * p;
    p = head;
    while (p != NULL)
    {
        printf("%d -> ", p -> data);
        p = p -> next;
    }
    printf("NULL\n");
}

node * intersection(node * head, node * head1, node * head2, int n1, int n2)
{
    node * p1, *p2;
    p1 = head1;
    for (int i = 0; i < n1; i++)
    {
        p2 = head2;
        for (int j = 0; j < n2; j++)
        {
            if ((p1 -> data) == (p2 -> data))
            {
                int found = 0;
                node * p = head;
                while (p != NULL)
                {
                    if ((p -> data) == (p1 -> data))
                    {
                        found = 1;
                        break;
                    }
                    p = p -> next;
                }
                if (!found)
                {
                    head = insert(head, p1 -> data);
                }
            }
            p2 = p2 -> next;
        }
        p1 = p1 -> next;
    }
    return head;
}

int main()
{
    printf("enter the sizes of the linked lists: ");
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    node * head1 = NULL;
    node * head2 = NULL;
    node * head = NULL;
    printf("LIST 1\n");
    for (int i = 0; i < n1; i++)
    {
        int value;
        printf("enter the data of node %d: ", i + 1);
        scanf("%d", &value);
        head1 = insert(head1, value);
    }
    printf("LIST 2\n");
    for (int i = 0; i < n2; i++)
    {
        int value;
        printf("enter the data of node %d: ", i + 1);
        scanf("%d", &value);
        head2 = insert(head2, value);
    }
    printf("first Linked List is: ");
    displayLL(head1);
    printf("second Linked List is: ");
    displayLL(head2);
    head = intersection(head, head1, head2, n1, n2);
    displayLL(head);
}