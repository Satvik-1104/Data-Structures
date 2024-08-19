#include <stdio.h>

void merge(int n, int a[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[n];
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if (i > mid)
    {
        while (j <= r){
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if (j > r)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            j++;
        }
    }
    for (int p = l; p <= r; p++)
    {
        a[p] = b[p];
    }
}

void sort(int n, int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r)/2;
        sort(n, a, l, mid);
        sort(n, a, mid + 1, r);
        merge(n, a, l, mid, r);
    }
}

int main()
{
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of the array: ");
    for (int i = 0;i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the given array is: ");
    for (int i = 0;i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    sort(n, a, 0, n-1);
    printf("the sorted array is: ");
    for (int i = 0;i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("the least element is %d\n", a[0]);
    printf("the greatest element is %d\n", a[n - 1]);
    return 0;
}