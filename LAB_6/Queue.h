#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
    Node* head;
    Node* tail;

    bool isEmpty() const;

public:
    Queue();
    ~Queue();
    void enqueue(const int data);
    int dequeue();
    void printQueue() const;
};

#endif