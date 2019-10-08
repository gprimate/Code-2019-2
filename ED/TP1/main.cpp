#include <iostream>
#include <cstdio>
#include "findOp.h"

int main() {
    int q;
    char e;
    LinkedList sizes;

   //Base do programa, que chama funcoes e metodos dos arquivos lista.cpp e findOp.cpp
   //Loop que termina quando o usuario digita ctrl d
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