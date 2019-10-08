#include "lista.h"
#include <iostream>

//Construtor da lista
LinkedList::LinkedList() {
    _start = nullptr;
    _end = nullptr;
    _numElements = 0;
}

//Desconstrutor da lista, tendo em vista que ela usa ponteiros
LinkedList::~LinkedList() {
    Node *current = _start;
    Node *aux = nullptr;

    while (current != nullptr) {
        aux = current;
        current = current->_next;
        delete aux;
    }
}

//Funcao que insere um novo elemento no final da lista
void LinkedList::insertElement(int element) {
    Node *newElement = new Node();

    newElement->_next = nullptr;
    newElement->_element = element;

    if (_start == nullptr) {
        _start = newElement;
        _end = newElement;

    } else {
        _end->_next = newElement;
        _end = newElement;
    }
    _numElements += 1;
}

//Funcao que remove um elemento
//Recebe como parametro o valor do elemento e nao o indice dele
void LinkedList::removeElement(int element) {
    Node *current = _start;
    int pos;

    //Loop para achar o indice do elemento
    for (int i = 0; i < _numElements; i++) {
        if (current->_element == element) {
            pos = i;
            break;
            
        } else {
            current = current->_next;
        }
    }
    // Faz a remocao de maneira e a religacao dos ponteiros
    if (pos == 0) {
        _start = current->_next;
        
    } else {
        Node * before = _start;

        for (int i = 0; i < pos - 1; i++) {
            before = before->_next;
        }

        if (pos == _numElements - 1) {
            
            before->_next = nullptr;
            _end = before;

        } else {
            before->_next = current->_next;
        }
    }

    _numElements -= 1;
    delete current; 
}


//Funcao que remove o primeiro elemento da lista
void LinkedList::removeFirst(){
    if (_numElements == 0) {
        return;
    }

    Node *current = _start;
    _start = current->_next;
    _numElements -= 1;

    delete current;
}


//Funcao que retorna o elemento desejado
//Recebe como parametro o indice do elemento 
int LinkedList::getElement(int pos) {
    if (pos >= _numElements) {
        exit(1);
    }
    
    if (pos == 0) {
        return _start->_element;

    } else if (pos == _numElements - 1) {
        return _end->_element;

    }else {
        Node current = *_start;

        for (int i = 0; i < pos; i++) {
            current = *current._next;
        }
        return current._element;
    }  
}


//Funcao que retorna o tamanho da lista
int LinkedList::size(){
    return _numElements;
}