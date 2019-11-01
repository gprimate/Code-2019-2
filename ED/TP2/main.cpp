#include "mergeSort.h"


int main() {
    int maxTime;
    int numPlanets;
    int numChar;

    std::cin >> maxTime >> numPlanets >> numChar;

    //std::cout << maxTime << " " << numPlanets << " " << numChar << std::endl;

    Planet planets[numPlanets];

    for(int i = 0; i < numPlanets; i++) {
        int visitTime;
        std::string name;

        std::cin >> visitTime >> name;
        planets[i] = Planet(name, visitTime);
    }


    mergeSort(planets, 0, numPlanets - 1);

    results(planets, numPlanets, maxTime, numChar);








   return 0; 
}
