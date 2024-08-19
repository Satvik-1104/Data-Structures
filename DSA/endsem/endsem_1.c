#include <stdio.h>

int sumofrow (int m, int n, int a[m][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[0][i];
    }
    return sum;
}

void product(int m, int n, int a[m][n], int sum)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] *= sum;
        }
    }
}

int main()
{
    printf("enter the size of matrix: ");
    int n, m;
    scanf("%d %d", &m, &n);
    int a[m][n];
    printf("enter the elements of the matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("the given matrix is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int rowsum = sumofrow(m, n, a);
    product(m, n, a, rowsum);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}