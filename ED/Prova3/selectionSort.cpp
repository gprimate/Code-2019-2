#include "selectionSort.h"


void selectionSort(int arr[], int size) {
    int i,j, minIdx;

    for(i = 0; i < size - 1; i++) {
        minIdx = i;

        for(j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}


void swap(int *x1, int *x2) {
    int aux = *x1;
    *x1 = *x2;
    *x2 = aux;
}