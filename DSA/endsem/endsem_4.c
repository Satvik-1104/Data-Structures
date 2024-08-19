#include <stdio.h>

int maxindex (int n, int a[])
{  
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    return max;
}

int main()
{
    int n, m;
    printf("enter the size of array: ");
    scanf("%d", &n);
    m = n;
    int a[n];
    printf("enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the given array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int m1 = maxindex(n, a);
    int max;
    if (m1 == 0)
    {
        max = a[1];
    }
    else
    {
        max = a[0];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == m1)
        {
            continue;
        }
        else
        {
            if (a[i] > max)
            {
                max = a[i];
            }
        }
    }
    printf("the second largest element is %d", max);
}