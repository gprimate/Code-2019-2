#include "mergeSort.h"


//Função merge, que junta dois vetores ordenados
void merge(Planet planets[], int left, int middle, int right) { 
    int i, j, k;

    int sizeL = middle - left + 1; 
    int sizeR =  right - middle; 
    
    //Cria uma copia dos vetores da esquerda e direita
    Planet * valuesL;
    valuesL = new Planet [sizeL];
    Planet * valuesR;
    valuesR = new Planet [sizeR];
    
    //Adiciona elementos no vetor da esquerda
    for (i = 0; i < sizeL; i++) {
        valuesL[i] = planets[i + left];
    }

    //Adiciona elementos no vetor da direita
    for (i = 0; i < sizeR; i++) {
        valuesR[i] = planets[middle + 1 + i];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    /*Ordena os elementos dos vetores da esquerda e direita e 
      guarda o vetor ordenado no vetor parâmetro */
    
    while (i < sizeL && j < sizeR) {
        if (valuesL[i].getTime() <= valuesR[j].getTime()) {
            planets[k] = valuesL[i];
            i++;

        } else {
            planets[k] = valuesR[j];
            j++;
        }
        k++;
    }
    
    //Adiciona os elementos restantes do vetor da esquerda, caso haja algum
    while (i < sizeL) {
        planets[k] =valuesL[i];
        i++;
        k++;
    }

    //Adiciona os elementos restantes do vetor da direita, caso haja algum
    while (j < sizeR) {
        planets[k] = valuesR[j];
        j++;
        k++;
    }
    delete[] valuesR;
    delete[] valuesL;
} 

//Função mergeSort em si, que chama a funcão merge
void mergeSort(Planet planets[], int left, int right){

    //Divide o vetor em dois e para de dividir quando eles tiverem um elemento
    if (left < right) {

        //Acha a posição central
        int middle = (left + right) / 2;

        //Chama recursivamente na metade esquerda
        mergeSort(planets, left, middle);

        //Chama recursivamente na metade esquerda
        mergeSort(planets, middle + 1, right);

        //Junta os elementos das partes esquerda e dieita
        merge(planets, left, middle, right); 
    }
}