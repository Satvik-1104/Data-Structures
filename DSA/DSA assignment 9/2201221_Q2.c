#include <stdio.h>

int maxelement(int n, int a[])
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int minelement(int n, int a[])
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int found(int n, int a[], int num)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            f = 1;
        }
    }
    return f;
}

int missingnumbers(int n, int a[], int min, int max)
{
    int temp = min;
    int empty = 1;
    while (temp < max)
    {
        if (!found(n, a, temp))
        {
            printf("%d ", temp);
            empty = 0;
        }
        temp++;
    }
    return empty;
}

int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the given numbers are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int max = maxelement(n, a);
    int min = minelement(n, a); 
    printf("the missing numbers are: ");
    int empty = missingnumbers(n, a, min, max);
    if (empty == 1)
    {
        printf("none");
    }
}