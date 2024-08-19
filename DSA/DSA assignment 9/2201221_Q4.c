#include <stdio.h>

int icecream(int n, int cost[], int m)
{
    int a, b;
    int set = 0;
    for (int i = 0; i < n; i++)
    {
        a = cost[i];
        for (int j = i + 1; j < n; j++)
        {
            b = cost[j];
            if (a + b == m)
            {
                set = 1;
                printf("The two flavours that cost %d and %d meet the criteria. Using 0-based indexing, they are at indices %d and %d.\n", a, b, i, j);
            }
        }
    }
    return set;
}

int main()
{
    int m, n;
    printf("amount of money pooled: ");
    scanf("%d", &m);
    printf("enter the number of flavours available: ");
    scanf("%d", &n);
    int cost[n];
    printf("enter the cost of each flavour: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cost[i]);
    }
    printf("the given costs of different flavours' icecreams are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", cost[i]);
    }
    printf("\n");
    int selectedflavours = icecream(n, cost, m);
    if (selectedflavours == 0)
    {
        printf("no such pair of flavours exist.");
    }
}