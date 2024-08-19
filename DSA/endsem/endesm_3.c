#include <stdio.h>

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
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] % 2 != 0)
        {
            int temp = a[i];
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            a[n - 1] = temp;
            n--;
        }
    }
    printf("the modified array is: ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}