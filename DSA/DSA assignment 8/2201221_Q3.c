#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void minheap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int kthelement(int arr[], int n, int k) {
    minheap(arr, k);

    for (int i = k; i < n; i++) {
        if (arr[i] > arr[0]) {
            arr[0] = arr[i];
            heapify(arr, k, 0);
        }
    }

    return arr[0];
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int kthLargest = kthelement(arr, n, k);

    printf("The %dth largest array element is %d.\n", k, kthLargest);

    return 0;
}
