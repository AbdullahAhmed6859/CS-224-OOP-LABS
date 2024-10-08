#include "Node.h"

Node::Node(const int d) : data(d), next(nullptr) {}

int Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

void Node::setData(const int d) {
    data = d;
}

void Node::setNext(Node* next_ptr) {
    next = next_ptr;
}