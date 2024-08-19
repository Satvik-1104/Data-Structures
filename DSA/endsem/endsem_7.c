#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * createLL (node * head, int n)
{
    node * temp; 
    node * p = head;
    for (int i = 0; i < n; i++){
        temp = (node *)malloc(sizeof(node));
        printf("enter the data of node %d: ", i + 1);
        scanf("%d", &(temp -> data));
        temp -> next = NULL;
        if (head == NULL)
        {
            head = temp;
            p = head;
        }
        else
        {
            p -> next = temp;
            p = p -> next;
        }
    }
    return head;
}

node * insertBEG(node * head)
{
    printf("enter the value to insert: ");
    int value;
    scanf("%d", &value);
    node * temp = (node *)malloc(sizeof(node));
    temp -> data = value;
    temp -> next = head;
    head = temp;
    return head;
}

node * deleteMID(node * head)
{
    node * temp = head;
    int pos;
    printf("enter the position to delete from: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = head -> next;
        temp -> next = NULL;
    }
    else
    {
    for (int i = 0; i < (pos - 2); i++)
    {
        temp = temp -> next;
    }
        node * prev = temp;
        node * succ = temp -> next -> next;
        temp = temp -> next;
        prev -> next = succ;
        temp -> next = NULL;
    }
    free(temp);
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

int main()
{
    printf("enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    node * head = NULL;
    head = createLL(head, n);
    printf("initial Linked List is: ");
    displayLL(head);
    int choice;
    printf("OPTIONS\n1)Insert at beginning\n2)Delete from position\n3)Display\n4)exit\n");
    while (1)
    {
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            head = insertBEG(head);
            break;
            
            case 2:
            head = deleteMID(head);
            break;

            case 3:
            displayLL(head);
            break;

            case 4:
            printf("EXIT");
            exit(1);

            default:
            printf("invalid choice");
        }
    }
    return 0;
}