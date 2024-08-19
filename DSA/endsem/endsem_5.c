#include <stdio.h>

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
    if (m == n)
    {
        int d1 = 0;
        int d2 = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    d1 += a[i][j];
                }
                if ((i + j) == (n - 1))
                {
                    d2 += a[i][j];
                }
            }
        }
        printf("the 1st diagonal sum is %d\n", d1);
        printf("the 2nd diagonal sum is %d\n", d2);

        int d;
        if (d1 > d2)
        {
            d = d1 - d2;
        }
        else
        {
            d = d2 - d1;
        }
        printf("the absolute difference of the diagonls is %d\n", d);
    }
    else
    {
        printf("the no. of rows and columns should be equal\n");
    }
}