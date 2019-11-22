#include "hash.h"

int main() {
    
    //Variavel para armazenar o numero de palavras e seu input
    int nWords;
    std::cin >> nWords;

    //Criação da hash table
    HashTable hash(nWords);

    //Adiciona elementos na hash table
    for (int i = 0; i < nWords; i++) {
        std::string word;
        std::cin >> word;

        hash.insert(word);
    }

    char op;
    std::string word;

    //Imprime a frequencia das palavras requeridas
    while (std::cin >> op >> word) {
        if (op == 'q'){
            std::cout<< hash.getFreq(word) << std::endl;
        }
    }
}
