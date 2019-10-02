#include "lista.h"
#include <iostream>


LinkedList::LinkedList() {
    _start = nullptr;
    _end = nullptr;
    _numElements = 0;
}


LinkedList::~LinkedList() {
    Node *current = _start;
    Node *aux = nullptr;

    while (current != nullptr) {
        aux = current;
        current = current->_next;
        delete aux;
    }
}


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


void LinkedList::removeElement(int element) {
    Node *current = _start;
    int pos;

    for (int i = 0; i < _numElements; i++) {
        if (current->_element == element) {
            pos = i;
            break;
            
        } else {
            current = current->_next;
        }
    }

    if (pos == 0) {
        _start = current->_next;
    }

    if (pos == _numElements - 1) {
        Node * before = _start;

        for (int i = 0; i < pos - 1; i++) {
            before = before->_next;
        }

        before->_next = nullptr;
        _end = before;
    }

    _numElements -= 1;
    delete current; 
}

void LinkedList::removeFirst(){
    if (_numElements == 0) {
        return;
    }

    Node *current = _start;
    _start = current->_next;
    _numElements -= 1;

    delete current;
}


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


int LinkedList::size(){
    return _numElements;
}