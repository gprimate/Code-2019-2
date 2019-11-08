#include "radixSort.h"

//Função que ordena em ordem alfabética considerando um caractere
void countingSort(Planet planets[], int sizeArr, int posChar) {
    //Vetor que guarda os planetas ordenados
    Planet ordered[sizeArr];

    //Vetor que guarda o número de vezes que cada letra do alfabeto ocorre
    int count[26];

    //Inicializa o vetor count com zeros
    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }

    //Adicona ao vetor count o númeoro de repetições de cada letra
    for(int i = 0; i < sizeArr; i++){
        count[planets[i].getName()[posChar] - 97] += 1;
    }

    //Adiona ao vetor count o elemento anterior dele mesmo
    for (int i = 1; i < 26; i++) {
        count[i] += count[i-1];
    }

    //Ordena o vetor e o guarda no vetor temporário
    for (int i = sizeArr - 1; i >= 0; --i) {
        ordered[count[planets[i].getName()[posChar] - 97] - 1] = planets[i];
        count[planets[i].getName()[posChar] - 97] -= 1;
    }

    //Coloca no vetor parâmetro os valores ordenados
    for(int i = 0; i < sizeArr; i++){
        planets[i] = ordered[i];
    }
}


//Função que ordena em ordem alfabética considerando o nome inteiro do planeta 
void radixSort(Planet planets[], int sizeArr, int numChar) {
    //Chama o Counting Sort para cada caractere dos nomes dos planetas 
    for (int i = numChar - 1; i >= 0; i--) {
        countingSort(planets, sizeArr, i);
    }
}