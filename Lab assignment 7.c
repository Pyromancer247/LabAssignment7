#include <stdio.h>

void bubbleSort(int arr[], int n, int *swapCount) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swapCount)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *swapCount) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*swapCount)++;
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swapCount1 = 0, swapCount2 = 0;

    bubbleSort(array1, n1, &swapCount1);
    selectionSort(array2, n2, &swapCount2);

    printf("Array 1:\n");
    printf("Number of swaps per value: %.2f\n", (float)swapCount1 / n1);
    printf("Total number of swaps: %d\n", swapCount1);

    printf("\nArray 2:\n");
    printf("Number of swaps per value: %.2f\n", (float)swapCount2 / n2);
    printf("Total number of swaps: %d\n", swapCount2);

    return 0;
}