#include "months.h"

//Função que checa em qual mês cada viagem ocorrerá 
void results(Planet planets[], int numPlanets, int maxTime, int numChar) {
    //Valores iniciais, o número de meses necessários começa em 1
    int numMonths = 1;
    int sumTime = 0;
    int start = 0;

    //Checa até que planeta poderá ser feita uma visita em um mês
    for(int i = 0; i < numPlanets; i++) {
        sumTime += planets[i].getTime();

        if (sumTime > maxTime) {
            //Imprime os valores de um mês
            printVisit(planets, start, i, numMonths, numChar);

            start = i;
            i -= 1;
            numMonths += 1;
            sumTime = 0;    
        }
    }
    //Imprime os valores restantes do último mês
    printVisit(planets, start, numPlanets, numMonths, numChar);
}


//Função que imprime as visitas a serem feitas
void printVisit(Planet planets[], int start, int end, int month, int numChar) {
    int j = 0;
    int size = end - start;

    //Cria um vetor temporário com os planetas
    Planet planetsMonth[size];
    
    //Coloca os valores dos nomes dos planetas e tempos de visita no vetor temporário
    for (int i = start; i < end; i++) {
        planetsMonth[j] = planets[i];
        j++;
    } 

    //Ordena os elementos do vetor em ordem alfabética
    radixSort(planetsMonth, size, numChar);

    //Imprime os resultados
    for (int i = 0; i < size; i++) {
        std::cout << month << " " << planetsMonth[i].getName() << " " << planetsMonth[i].getTime() << std::endl;
    }
}