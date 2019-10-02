#include <iostream>
#include <cstdio>
#include "findOp.h"

int main() {
    int q;
    char e;
    LinkedList sizes;
   

    while(scanf("%d %c", &q, &e) != EOF) {
        if (e == 'i') {
            sizes.insertElement(q);

        } else if (e == 'p') {
            printf("%d\n", numOp(q,sizes));

        }  else if (e == 'r') {
            sizes.removeElement(q);
        }       
    }

    
    
    // for (int i=0; i < sizes.size(); i++) {
    //     newSizes.insertElement(sizes.getElement(i));
    // }

    // sizeB = newSizes.size();
    // addItems(sizes, newSizes);

    // std::cout << "----------" << std::endl;
    // std::cout << sizeB << std::endl;
    // std::cout << "----------" << std::endl;
    

    // for (int i = 0; i < sizeB; i++){
    //         newSizes.removeFirst();
    // }
    // for (int i = 0; i < newSizes.size(); i++) {
    //     std::cout << newSizes.getElement(i) << std::endl;
    // }

    // sizeB = newSizes.size();
    // addItems(sizes, newSizes);

    // std::cout << "----------" << std::endl;
    // std::cout << sizeB << std::endl;
    // std::cout << "----------" << std::endl;

    // for (int i = 0; i < sizeB; i++){
    //         newSizes.removeFirst();
    // }

    // for (int i = 0; i < newSizes.size(); i++) {
    //     std::cout << newSizes.getElement(i) << std::endl;
    // }
    
    return 0;
}