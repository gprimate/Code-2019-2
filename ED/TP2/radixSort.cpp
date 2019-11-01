#include "radixSort.h"

void countingSort(Planet planets[], int sizeArr, int posChar) {
    Planet ordered[sizeArr];

    int count[26];

    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }

    for(int i = 0; i < sizeArr; i++){
        count[planets[i].getName()[posChar] - 97] += 1;
    }

    for (int i = 1; i < 26; i++) {
        count[i] += count[i-1];
    }

    for (int i = sizeArr - 1; i >= 0; --i) {
        ordered[count[planets[i].getName()[posChar] - 97] - 1] = planets[i];
        count[planets[i].getName()[posChar] - 97] -= 1;
    }

    for(int i = 0; i < sizeArr; i++){
        planets[i] = ordered[i];
    }
}



void radixSort(Planet planets[], int sizeArr, int numChar) {
    for (int i = numChar - 1; i >= 0; i--) {
        countingSort(planets, sizeArr, i);
    }
}