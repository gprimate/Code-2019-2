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

}