#include <stdio.h>
#include <stdlib.h>

int size = 0;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void insertionInHeap(int arr[], int val) {
    size = size + 1;
    arr[size] = val;
    int i = size;
    while (i > 1) {
        int parent = i / 2;
        if (arr[parent] < arr[i]) {
            swap(&arr[parent], &arr[i]);
            i = parent;
        }
        else {
            return;
        }
    }
}

void deletionInHeap(int arr[]) {
    arr[1] = arr[size];
    size = size - 1;
    int i = 1;
    while (i < size) {
        int left = arr[2 * i];
        int right = arr[(2 * i) + 1];
        int larger = left > right ? 2 * i : (2 * i) + 1;
        if (arr[i] < arr[larger]) {
            swap(&arr[i], &arr[larger]);
            i = larger;
        }
        else {
            return;
        }
    }
}

void deletionAtIndex(int arr[], int index) {
    arr[index] = arr[size];
    size = size - 1;
    int i = 1;
    while (2 * i <= size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int larger = left;

        if (right <= size && arr[right] > arr[left]) {
            larger = right;
        }

        if (arr[i] < arr[larger]) {
            swap(&arr[i], &arr[larger]);
            i = larger;
        } 
        else {
            return;
        }
    }
}
void print(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int n;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    int * arr = (int *) malloc(sizeof(int)*n);

    printf("Enter elements in array: \n");
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertionInHeap(arr, val);
    }
    printf("THE HEAP IS :");
    print(arr, size);

    printf("\nEnter the elemet to insert :");
    int ele;
    scanf("%d", &ele);
    insertionInHeap(arr, ele);
    printf("HEAP AFTER INSERION :");
    printf("\n");
    print(arr, size);
    printf("\nENTER THE INDEX TO DELETE :");
    int index;
    scanf("%d", &index);
    deletionAtIndex(arr, index);
    printf("HEAP AFTER DELETION\n");
    print(arr, size);
    

    return 0;
}