#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    unsigned int size, numDequeue;
    cin >> size;
    Queue q;

    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        q.enqueue(data);
    }

    cin >> numDequeue;
    q.printQueue();

    for (int i = 0; i < numDequeue; i++)
        q.dequeue();

    q.printQueue();
    cout << endl;
    return 0;
}