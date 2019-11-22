#include "hash.h"


//Construtor da hash table, recebe como parâmetro o número de palavras
HashTable::HashTable(int n) {
    size = n;
    table = new Cell*[n];

    for (int i = 0; i < size; i++) {
        table[i] = new Cell;
        table[i]->word = "";
        table[i]->next = nullptr;
    }
}



//Destrutor da hash table, para eliminar memory leaks
HashTable::~HashTable(){
    for (int i = 0; i < size; i++) {
        deleteCell(table[i]);
    }

    delete []table; 
}



//Método recursivo que auxilia o destrutor
void HashTable::deleteCell(Cell* cell) {
    if (cell->next == nullptr) {
        delete cell;
    } else {
        deleteCell(cell->next);
        delete cell;
    }
}



//Método que cria a chave para uma determinada palavra
int HashTable::hash(std::string word) {
    int hash = 0;

    for (unsigned int i = 0; i < word.length(); i++) {
        hash = hash + (int)word[i];
    }

    return hash % size;
}



//Método que retorna a frequencia de uma determinada palavra
int HashTable::getFreq(std::string word) {
    int index = hash(word);

    Cell* aux = table[index];
    
    while (aux != nullptr) {
        if (aux->word == word) {
            return aux->count;

        } else {
            aux = aux->next;
        }
    }
    return 0;
}



//Método que insere uma palavra na hash table
void HashTable::insert(std::string word) {
    int index = hash(word);

    Cell* aux = table[index];

    // Cria uma nova célula caso a palavra seja inédita e soma no count caso contrário
    if (aux->word == "") {
        table[index]->word = word;
        table[index]->count = 1;

    } else {
       bool neverSeen = true;

        while(aux->next != nullptr) {
            if (aux->word == word) {
                aux->count += 1;
                neverSeen = false;
                break;
            }
            aux = aux->next;
        }

        if (neverSeen) {
            if (aux->word == word) {
                aux->count += 1;

            } else {
                Cell* newCell = new Cell;
                newCell->word = word;
                newCell->count = 1;
                newCell->next = nullptr;
                aux->next = newCell;
           }
        }
    }
}