#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "SortingStrategy.h"
class SelectionSort : public SortingStrategy {
public:
    // void print(int arr[], int n);
    void sort(int *arr, int n);
};
#endif