#include "mergeSort.h"


int main() {
    
    int maxTime;
    int numPlanets;
    int numChar;

    // Obtém o número de planetas, de caracteres e o tempo maximo de visitação
    std::cin >> maxTime >> numPlanets >> numChar;

    Planet planets[numPlanets];

    // Obtém os nomes dos planetas o tempo de visitação em cada um deles
    for(int i = 0; i < numPlanets; i++) {

        int visitTime;
        std::string name;

        std::cin >> visitTime >> name;
        planets[i] = Planet(name, visitTime);
    }

    //Faz o merge sort
    mergeSort(planets, 0, numPlanets - 1);

    //Imprime os resultados 
    results(planets, numPlanets, maxTime, numChar);

   return 0; 
}
