/* Array.h
 * The definition of the Array class template for various types of arrays.
 * author: Syed Hammad Ahmed
 */
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T> class Array {
private:
    T *array;
    int size;

public:
    Array();
    Array(int size);
    // Rule of 3 methods
    Array(const Array<T> &arg); // Copy constructor
    Array<T> &operator=(const Array<T> &arg);
    ~Array();

    void print() const;
    void input();
};

template <typename T> void mySwap(T &a, T &b);
template <typename T> void sort(T arr[], int n);

#include "Array.tpp" // Include the template implementation file

#endif
