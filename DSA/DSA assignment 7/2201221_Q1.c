#define M 50
#define N 50

#include <stdio.h>
#include <string.h>

char ** insertionsort(char c[M][N])
{
    char temp[N];
    for (int i = 1; c[i][0] != '\0'; i++)
    {
        strcpy(temp, c[i]);
        int j = i - 1;
        while (j >= 0 && (strcmp(c[j], temp) > 0))
        {
            strcpy(c[j + 1], c[j]);
            j--;
        }
        strcpy(c[j + 1], temp);
    }
}

void Displaylist(char c[][N])
{
    printf("\nthe list of strings in alphabetical order is\n");
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
    insertionsort(c);
    Displaylist(c);
    return 0;
}