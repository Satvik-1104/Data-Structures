#include <stdio.h>
#include <string.h>

#define N 100

int top = -1;
char stack[N];

void push(char c)
{
    if (top = N - 1)
    {
        printf("OVERFLOW\n");
        exit(1);
    }
    else 
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("UNDERFLOW\n");
        exit(1);
    }
    char popped = stack[top];
    top--;
    return popped;
}

void rev(int l, char s[])
{
    for (int i = 0; i < (l + 1) / 2; i++)
    {
        char c = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = c;
    }
}



int main()
{
    char s[N];
    printf("enter the string: ");
    fgets(s, N, stdin);
    s[strcspn(s, "\n")] = '\0';
    printf("the given string is: ");
    puts(s);
    int l = strlen(s);
    rev(l, s);
    printf("the reversed string is: ");
    puts(s);
}