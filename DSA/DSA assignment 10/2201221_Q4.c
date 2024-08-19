#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void maxheap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int kthLargest(int arr[], int n, int k) {
    maxheap(arr, n);

    for (int i = 1; i < k; i++) {
        swap(&arr[0], &arr[n - i]);
        heapify(arr, n - i, 0);
    }

    return arr[0];
}

int main() {
    int n;
    printf("Enter the number of elements in the maxheap: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the maxheap: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int kthLargestElement = kthLargest(arr, n, k);

    printf("The %dth largest element in the maxheap is %d.\n", k, kthLargestElement);

    return 0;
}
