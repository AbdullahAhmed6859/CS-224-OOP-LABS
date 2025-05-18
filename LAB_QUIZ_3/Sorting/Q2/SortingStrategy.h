#ifndef SORTINGSTRATEGY_H
#define SORTINGSTRATEGY_H
class SortingStrategy {
public:
    void print(int *arr, int n);
    virtual void sort(int *arr, int n) = 0;
};
#endif