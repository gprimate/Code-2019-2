#include <iostream>
#include "lista.h"

int main() {
    
    LinkedList GG;

    GG.insertElement(0);
    GG.insertElement(1);
    GG.insertElement(2);
    GG.insertElement(3);
    GG.insertElement(4);
    GG.insertElement(5);
    GG.insertElement(6);
    GG.removeFirst();
    GG.removeFirst();
    GG.removeFirst();

    int size = GG.size();

    for (int i = 0; i < size; i++){
        std::cout<< GG.getElement(i) << std::endl;
    }

    GG.~LinkedList();
    return 0;
}
