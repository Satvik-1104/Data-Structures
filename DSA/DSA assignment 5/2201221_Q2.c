#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct StackNode 
{
    char data;
    struct StackNode * next;
}stacknode;

stacknode * createnode (char data)
{
    stacknode * newnode = (stacknode*)malloc(sizeof(stacknode));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

void push (stacknode ** top, char data)
{
    stacknode * newnode = createnode(data);
    newnode -> next = *top;
    *top = newnode;
}

int IsEmpty(stacknode* top)
{
    return top == NULL;
}

char pop (stacknode ** top)
{
    if (IsEmpty(*top))
    {
        printf("UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    stacknode * temp;
    temp = * top;
    char popped = temp -> data;
    * top = (* top) -> next;
    free(temp);
    return popped;
}

char peek(stacknode * top)
{
    if (IsEmpty(top))
    {
        printf("UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    return top -> data;
}

void wordsreverse(char * s)
{
    int l = strlen(s);
    stacknode * stack = NULL;
    for (int i = 0; i < l; i++)
    {
        if (s[i] != ' ')
        {
            push(&stack, s[i]);
        }
        else 
        {
            while (!(IsEmpty(stack)))
            {
                printf("%c", pop(&stack));
            }
            printf(" ");
        }
    }
    while (!(IsEmpty(stack)))
    {
        printf("%c", pop(&stack));
    }
}

int main()
{
    char s[MAX];
    printf("enter the string: ");
    gets(s);
    printf("the given string is: ");
    puts(s);
    printf("the updated string is: ");
    wordsreverse(s);
}