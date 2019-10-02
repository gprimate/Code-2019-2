#include "findOp.h"


int numOp(int ml, LinkedList & sizes) {
    if (ml == 0){
        return 0;
    }

    LinkedList newSizes;
    
    for (int i=0; i < sizes.size(); i++) {
        newSizes.insertElement(sizes.getElement(i));
    }

    int op = 1;

    while (1) {
        if (checkWin(ml, newSizes)) {
            return op;

        } else {
            int sizeB = newSizes.size();

            addItems(sizes, newSizes);
            op += 1;

            for (int i = 0; i < sizeB; i++){
                newSizes.removeFirst();

                
            }
            
        }
    }
}




bool checkWin(int ml, LinkedList  & newSizes) {
    for (int i = 0; i < newSizes.size(); i++){
        if (newSizes.getElement(i) == ml) {
            return true;
        }
    }   
    return false;
}




void addItems(LinkedList & sizes, LinkedList & newSizes) {

    int nSize = newSizes.size();
    
    for(int i = 0; i < sizes.size(); i++) {

        for (int j= 0; j < nSize; j++) {
            newSizes.insertElement(newSizes.getElement(j) + sizes.getElement(i));            
            int sub = newSizes.getElement(j) - sizes.getElement(i);

            if (sub > 0){
                newSizes.insertElement(sub);
            } 
        }
    } 
}

