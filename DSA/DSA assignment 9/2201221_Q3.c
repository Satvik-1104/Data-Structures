#include <stdio.h>

void merge(int n, int s[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[n];
    while ((i <= mid) && (j <= ub))
    {
        if (s[i] < s[j])
        {
            b[k] = s[i];
            i++;
        }
        else
        {
            b[k] = s[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = s[j];
            k++;
            j++;
        }
    }
    if (j > ub)
    {
        while (i <= mid)
        {
            b[k] = s[i];
            k++;
            i++;
        }
    }
    for (int p = lb; p <= ub; p++)
    {
        s[p] = b[p];
    }
}

void mergesort(int n, int s[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub)/2;
        mergesort(n, s, lb, mid);
        mergesort(n, s, mid + 1, ub);
        merge(n, s, lb, mid, ub);
    }
}

int updatesweetness(int n, int s[], int k)
{
    mergesort(n, s, 0, (n - 1));
    int operations = 0;
    while (s[0] < k)
    {
        if (n < 2)
        {
            return -1;
        }
        int newsweetness = (1 * s[0]) + (2 * s[1]);
        s[0] = newsweetness;
        for (int i = 1; i < n - 1; i++)
        {
            s[i] = s[i + 1];
        }
        n--;
        operations++;
        mergesort(n, s, 0, (n - 1));
        printf("after operation %d\n", operations);
        printf("the new array is: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
    return operations;
}

int main()
{
    int k;
    printf("enter the threshold sweetness value: ");
    scanf("%d", &k);
    int n;
    printf("enter the number of cookies: ");
    scanf("%d", &n);
    int s[n];
    printf("enter the swrrtness of each cookie: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    printf("the threshold sweetness given is: %d\n", k);
    printf("the entered sweetness of the cookies is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
   int count = updatesweetness(n, s, k);
   if (count == 0)
   {
    printf("all the cookies are sweet enough");
   }
   else if (count == -1)
   {
    printf("not possible");
   }
   else
   {
    printf("for '%d' operations, the sweetness of all the cookies crossed the threshold sweetness", count);
   }
}