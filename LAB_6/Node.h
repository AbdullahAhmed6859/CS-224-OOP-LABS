#ifndef NODE_H
#define NODE_H

class Node {
    int data;
    Node* next;

public:
    Node(const int d);
    int getData() const;
    Node* getNext() const;
    void setData(const int d);
    void setNext(Node* next_ptr);
};

#endif