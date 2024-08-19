#define M 50
#define N 50

#include <stdio.h>
#include <string.h>

void linearsearch(char c[][N], char string[N])
{
    int flag = 0;
    for (int i = 0; c[i][0] != '\0'; i++)
    {
        if (strcmp(string, c[i]) == 0)
        {
            printf("\nthe string you searched for is ");
            puts(c[i]);
            printf("its first occurence is at position (%d) or index (%d) in the given list\n", i+1, i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\nthe string is not present in the list\n");
    }
}

void Displaylist(char c[][N])
{
    printf("\nthe list of strings entered is\n");
    for (int i = 0; c[i][0] != '\0'; i++)
    {
        puts(c[i]);
    }
}

int main()
{
    char c[M][N];
    printf("enter the strings\n");
    for (int i = 0; i < M; i++)
    {
        fgets(c[i], N, stdin);
        c[i][strcspn(c[i], "\n")] = '\0';
        if (strcmp(c[i], "") == 0)
        {
            break; 
        }
    }
    printf("enter the string to search for: ");
    char string[N];
    fgets(string, N, stdin);
    string[strcspn(string, "\n")] = '\0';
    Displaylist(c);
    linearsearch(c, string);
    return 0;
}