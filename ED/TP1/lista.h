#ifndef __TP1_ED___
#define __TP1_ED__


//O elemento básico da lista, que armazena um inteiro e aponta proximo item da lista
class Node {
public:
    int _element;
    Node *_next;
};

//A lista em si, que possui nodes de inicio e fim
//Tambem possui uma variavel que armazena o numero de elementos da lista
class LinkedList {
private:
    Node *_start;
    Node *_end;
    int _numElements;

public:
    LinkedList();
    ~LinkedList();

    void insertElement(int element);
    void removeElement(int element);
    void removeFirst();

    int getElement(int pos);
    int size();
};

#endif