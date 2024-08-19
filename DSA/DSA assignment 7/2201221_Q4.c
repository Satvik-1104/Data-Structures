#include <stdio.h>
#include <stdlib.h>

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int a[], int n)
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (b[j] > b[j+1])
            {
                swap(&b[j], &b[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("the list after bubble sort is: ");
    display(b, n);
}

void selectionsort(int a[], int n)
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (b[j] < b[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap (&b[i], &b[min]);
        }
    }
    printf("the list after insertion sort is: ");
    display(b, n);
}

void insertionsort(int a[], int n)
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int temp = b[i];
        int j = i - 1;
        while (j >= 0 && temp < b[j])
        {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = temp;
    }
    printf("the list after selection sort is: ");
    display(b, n);
}

int main()
{
    int n;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the array before sorting is: ");
    display(a, n);
    int ch;
    while (1)
    {
        printf("Enter your choice\nMENU\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n"); 
        printf("enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                bubblesort(a, n);
                break;
            
            case 2:
                selectionsort(a, n);
                break;
            
            case 3:
                insertionsort(a, n);
                break;

            case 4: 
                exit(0);

            default:
                    printf("invalid choice\n");
        }
    }
}