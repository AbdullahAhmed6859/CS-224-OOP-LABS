#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "SortingStrategy.h"

class BubbleSort : public SortingStrategy {
public:
    // void print(int arr[], int n);
    void sort(int *arr, int n);
};

#endif