#ifndef __TP1_ED___
#define __TP1_ED__

class Node {
public:
    int _element;
    Node *_next;
};

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