#include <stdio.h>

void merge(int n, int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[n];
    while ((i <= mid) && (j <= ub))
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if (j > ub)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (int p = lb; p <= ub; p++)
    {
        a[p] = b[p];
    }
}

void mergesort(int n, int a[], int lb, int ub)
{
    if (lb < ub)
    {
       int mid = (lb + ub)/2;
       mergesort(n, a, lb, mid);
       mergesort(n, a, mid + 1, ub);
       merge(n, a, lb, mid, ub);
    }
}

int duplicateelements(int n, int a[])
{
    int dup = 0;
    int count = 1;
    for (int i = 0; i < (n-1); i++)
    {  
        if (a[i] == a[i+1])
        {
            count++;
            dup = 1;
            if (i == (n - 2))
            {
                printf("%d occured %d times\n", a[i], count);
            }
        }
        else if (a[i] != a[i+1])
        {
            if (count != 1)
            {
                printf("%d occured %d times\n", a[i], count);
                count = 1;
            }
        }
    }
    return dup;
}

int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of the array: ");
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
    mergesort(n, a, 0, n-1);
    printf("the sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int dupelements = duplicateelements(n, a);
    if (dupelements == 0)
    {
        printf("there are no repeating elements");
    }
}