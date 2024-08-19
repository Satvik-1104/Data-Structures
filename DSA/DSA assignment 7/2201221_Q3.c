#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * createLL(node * head)
{
    node *p, *temp;
    p = head;
    printf("enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (node*)malloc(sizeof(node));
        printf("enter the data for node %d: ", i+1);
        scanf("%d", &(temp -> data));
        temp -> next = NULL;
        if (head == NULL)
        {
            head = temp;
            p = head;
        }
        else
        {
            while ((p -> next) != NULL)
            {
                p = p -> next;
            }
            p -> next = temp;
        }
    }
    return head;
}

void displayLL(node * head)
{
    node * p;
    p = head;
    while (p != NULL)
    {
        printf("%d -> ", (p -> data));
        p = p -> next;
    }
    printf("NULL\n");
}

node * merge(node * left, node * right)
{
    if (left == NULL)
    return right;
    if (right == NULL)
    return left;
    node * result = NULL;
    if ((left -> data) <= (right -> data))
    {
        result = left;
        result -> next = merge((left -> next), right);
    }
    else
    {
        result = right;
        result -> next = merge(left, (right -> next));
    }
    return result;
}

node * mergesort(node * head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    node * a = head;
    node * b = head -> next;
    while (b != NULL && b -> next != NULL)
    {
        a = a -> next;
        b = b -> next -> next;
    }
    node * right = a -> next;
    a -> next = NULL;
    node * left_sorted = mergesort(head);
    node * right_sorted = mergesort(right);
    node * sorted_list = merge(left_sorted, right_sorted);
} 

int main()
{
    node * head = NULL;
    head = createLL(head);
    printf("the original linked list is: ");
    displayLL(head);
    head = mergesort(head);
    printf("the list after sorting is: ");
    displayLL(head);
    return 0;
}