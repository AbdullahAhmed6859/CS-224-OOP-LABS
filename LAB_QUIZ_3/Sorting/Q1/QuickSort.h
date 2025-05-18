#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "SortingStrategy.h"
class QuickSort : public SortingStrategy {
public:
    // void print(int arr[], int n);
    void sort(int *arr, int n);

private:
    int partition(int *arr, int low, int high);
    void quickSort(int *arr, int low, int high);
};
#endif