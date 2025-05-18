/* Array.tpp
 * The implementation of the Array class template functions.
 * author: Syed Hammad Ahmed
 */

#include <iostream>

#include "Array.h"
using namespace std;

template <typename T> Array<T>::Array() : array(NULL), size(10) {
}

template <typename T> Array<T>::Array(int size) : size(size) {
    array = new T[size];
}

template <typename T> Array<T>::Array(const Array<T> &arg) : size(arg.size) {
    array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = arg.array[i];
    }
}

template <typename T> Array<T>::~Array() {
    delete[] array;
}

template <typename T> void Array<T>::print() const {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Input elements into the array
template <typename T> void Array<T>::input() {
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }
}

// Assignment operator
template <typename T> Array<T> &Array<T>::operator=(const Array<T> &arg) {
    if (this != &arg) {
        if (this->size != arg.size) {
            this->size = arg.size;
            delete[] array;
            array = new T[size];
        }
        for (int i = 0; i < size; i++)
            array[i] = arg.array[i];
    }
    return (*this);
}

template <typename T> void mySwap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

template <typename T> void sort(T arr[], int n) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        mySwap(array[min_idx], array[step]);
    }
}
