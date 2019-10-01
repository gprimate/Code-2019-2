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
    void removeFirst();

    int getElement(int pos);
    int size();
};