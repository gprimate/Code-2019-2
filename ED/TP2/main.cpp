
#include "mergeSort.h"
#include <iostream>

int main()
{
    Planet lista[6];

    lista[0] = Planet("Roninho", 0);
    lista[1] = Planet("Roninho", 3);
    lista[2] = Planet("Roninho", 5);
    lista[3] = Planet("Roninho", 2);
    lista[4] = Planet("Roninho", 4);
    lista[5] = Planet("Roninho", 1);

    
    

    mergeSort(lista, 0, 5);


    for (int i = 0; i < 6; i++) {
        std::cout << lista[i].getTime()  << std::endl;
    }
    
    return 0;
}
