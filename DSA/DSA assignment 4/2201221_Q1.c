#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

node * createdoublyLL(int n)
{
    node *temp, *p, *head;
    head = NULL;
    printf("enter the elements of the doubly LL\n");
    for (int i = 0; i < n; i++)
    {
        printf("enter the data of node %d: ", i + 1);
        temp = (node *)malloc(sizeof(node));
        scanf("%d", &(temp -> data));
        temp -> next = NULL;
        temp -> prev = NULL;
        p = head;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            while (p -> next != NULL)
            {
                p = p -> next;
            }
            p -> next = temp;
            temp -> prev = p;
            p = p -> next;
        }
    }
    return head;
}

void displaydoublyLL(node * head)
{
    node *p, *q;
    p = head;
    q = head;
    printf("in forward direction:\n");
    while (p != NULL)
    {
        printf("%d -> ", (p -> data));
        p = p -> next;
    }
    printf("NULL\n");
    printf("in backward direction:\n");
    while (q -> next != NULL)
    {
        q = q -> next;
    }
    while (q != head)
    {
        printf("%d -> ", (q -> data));
        q = q -> prev;
    }
    printf("%d -> NULL\n", (q -> data));
}

node * sortdoublyLL(node * head, int n)
{
    node *p, *q;
    p = head;
    while (p -> next != NULL)
    {
        q = p -> next;
        while (q != NULL)
        {
            if ((q -> data) < (p -> data))
            {
                int temp;
                temp = q -> data;
                q -> data = p -> data;
                p -> data = temp;
            }
            q = q -> next;
        }
        p = p -> next;
    }
    return head;
}

node * mergeLL(node * head1, node * head2)
{
    node * head = head1;
    node * end1 = head;
    while (end1 -> next != NULL)
    {
        end1 = end1 -> next;
    }
    end1 -> next = head2;
    head2 -> prev = end1;
    return head;
}

int main()
{
    int n1, n2;
    printf("enter the size of the 1st doubly linked list:\n");
    scanf("%d", &n1);
    node * head1 = createdoublyLL(n1);
    printf("enter the size of the 2nd doubly linked list:\n");
    scanf("%d", &n2);
    if (n1 == 0 && n2 == 0)
    {
        printf("the lists are empty\n");
    }
    else
    {
    node * head2 = createdoublyLL(n2);
    printf("the first doubly LL is\n");
    displaydoublyLL(head1);
    printf("the sorted 1st doubly linked list\n");
    head1 = sortdoublyLL(head1, n2);
    displaydoublyLL(head1);
    printf("the second doubly LL is\n");
    displaydoublyLL(head2);
    printf("the sorted 2nd doubly linked list\n");
    head2 = sortdoublyLL(head2, n2);
    displaydoublyLL(head2);
    node * head = mergeLL(head1, head2);
    printf("the merged linked list is\n");
    displaydoublyLL(head);
    printf("the sorted merged doubly linked list is\n");
    sortdoublyLL(head, (n1+n2));
    displaydoublyLL(head);
    }
}