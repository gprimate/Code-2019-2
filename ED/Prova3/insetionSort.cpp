#include "insertionSort.h"

void insertionSort(int arr[], int size) {
    int i,j, value;

    for(i = 1; i < size; i++) {
        value = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}