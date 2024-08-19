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

void revsecHALF(node * head, int pos)
{
    node * bef, * lat, * cur, * fhe;
    fhe = bef = head;
    for (int i = 0; i < (pos - 1); i++)
    {
        fhe = fhe -> next;
    }
    bef = fhe -> next;
    cur = bef -> next;
    lat = cur;
    bef -> next = NULL;
    while (lat != NULL)
    {
        lat = lat -> next;
        cur -> next = bef;
        bef = cur;
        cur = lat;
    }
    fhe -> next = bef;
}

int isPalindrome(node * head, int pos)
{
    node * fh, * sh;
    fh = sh = head;
    for (int i = 0; i < pos; i++)
    {
        sh = sh -> next;
    }
    while (sh != NULL)
    {
        if ((fh -> data) != (sh -> data))
        {
            return 0;
        }
        fh = fh -> next;
        sh = sh -> next;
    }
    return 1;
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
    int pos = (n + 1) / 2;
    revsecHALF(head, pos);
    displayLL(head);
    int check = isPalindrome(head, pos);
    if (check == 0)
    {
        printf("not a palindrome");
    }
    else
    {
        printf("a palindrome");
    }
    return 0;
}