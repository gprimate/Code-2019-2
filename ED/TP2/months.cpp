#include "months.h"

void results(Planet planets[], int numPlanets, int maxTime, int numChar) {
    int numMonths = 1;
    int sumTime = 0;
    int start = 0;

    for(int i = 0; i < numPlanets; i++) {
        sumTime += planets[i].getTime();

        if (sumTime > maxTime) {
            printVisit(planets, start, i, numMonths, numChar);

            start = i;
            i -= 1;
            numMonths += 1;
            sumTime = 0;    
        }
    }
    printVisit(planets, start, numPlanets, numMonths, numChar);
}



void printVisit(Planet planets[], int start, int end, int month, int numChar) {
    int j = 0;
    int size = end - start;

    Planet planetsMonth[size];
    

    for (int i = start; i < end; i++) {
        planetsMonth[j] = planets[i];
        j++;
    } 

    radixSort(planetsMonth, size, numChar);

    for (int i = 0; i < size; i++) {
        std::cout << month << " " << planetsMonth[i].getName() << " " << planetsMonth[i].getTime() << std::endl;
    }
}