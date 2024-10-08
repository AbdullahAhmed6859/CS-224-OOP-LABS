#include "Queue.h"
#include <iostream>

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (head != nullptr) {
        const Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::enqueue(const int data) {
    Node* new_node = new Node(data);

    if (isEmpty()) {
        head = new_node;
        tail = new_node;
    } else {
        tail->setNext(new_node);
        tail = new_node;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        return -1;
    }

    const int data = head->getData();

    const Node* temp = head;
    head = head->getNext();
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }

    return data;
}

void Queue::printQueue() const {
    if (isEmpty()) {
        std::cout << "queue is empty" << std::endl;
        return;
    }

    const Node* nodePtr = head;
    while (nodePtr != nullptr) {
        std::cout << nodePtr->getData() << " ";
        nodePtr = nodePtr->getNext();
    }
    std::cout << std::endl;
}