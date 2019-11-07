#include <iostream>
#include "insertionSort.h"



int main(int argc, char const *argv[]) {
    int banana[] = {5,7,8,3,4,2,6,1};

    insertionSort(banana, 8);

    for (int i = 0; i < 8; i++) {
        std::cout <<banana[i] << std::endl;
    }

    return 0;
}
