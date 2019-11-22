#include <iostream>
#include <string>


//Celulas da hash table
struct Cell {
    std::string word;
    Cell* next;
    int count;
};


//A hash table e seus métodos
class HashTable {
public:
    HashTable(int);
    ~HashTable();
    void deleteCell(Cell*);
    void insert(std::string);
    int hash(std::string);
    int getFreq(std::string);
    
private:
    int size; 
    Cell **table;
};