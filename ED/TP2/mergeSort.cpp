#include "mergeSort.h"

void merge(Planet planets[], int left, int middle, int right) { 
    int i, j, k;

    int sizeL = middle - left + 1; 
    int sizeR =  right - middle; 

    Planet valuesL[sizeL];
    Planet valuesR[sizeR];


    for (i = 0; i < sizeL; i++) {
        valuesL[i] = planets[i + left];
    }

    for (i = 0; i < sizeR; i++) {
        valuesR[i] = planets[middle + 1 + i];
    }


    i = 0;
    j = 0;
    k = left;


    while (i < sizeL && j < sizeR) {
        if (valuesL[i].getTime() <= valuesR[j].getTime()) {
            planets[k] = valuesL[i];
            i++;

        } else {
            planets[k] = valuesR[j];
            j++;
        }
        k++;
    }
    

    while (i < sizeL) {
        planets[k] =valuesL[i];
        i++;
        k++;
    }

    while (j < sizeR) {
        planets[k] = valuesR[j];
        j++;
        k++;
    }
} 

void mergeSort(Planet planets[], int left, int right){
    if (left < right) {
        int middle = (left + right) / 2;

        mergeSort(planets, left, middle);
        mergeSort(planets, middle + 1, right);
        merge(planets, left, middle, right); 
    }
}