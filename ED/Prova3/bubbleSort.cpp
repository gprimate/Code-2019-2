#include "bubbleSort.h"


void bubbleSort(int arr[], int size) {
    bool swapMade; //opicional

    for (int i = 0; i < size - 1; i++) {
        swapMade = false;

        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapMade = true;
            }
        }
        if (!swapMade) {
            break;
        }
    }
}


