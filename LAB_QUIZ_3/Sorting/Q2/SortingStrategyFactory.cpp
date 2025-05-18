#include "SortingStrategyFactory.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
// #include <string>
// using std::string;

SortingStrategy *SortingStrategyFactory::makeSortingStrategy(const string &algo) {
    // "Bubble Sort", "Selection Sort", "Quick Sort"
    if (algo == "Bubble Sort")
        return new BubbleSort();
    else if (algo == "Selection Sort")
        return new SelectionSort();
    else
        return new QuickSort();
}