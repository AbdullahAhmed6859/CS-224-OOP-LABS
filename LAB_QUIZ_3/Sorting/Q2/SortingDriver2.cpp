#include "SortingStrategy.h"
#include "SortingStrategyFactory.h"
#include <string>
using namespace std;
#define N 10

int main() {
    int array[] = {9, 7, 5, 3, 2, 1, 4, 8, 6, 0};

    string strategy_name[] = {"Bubble Sort", "Selection Sort", "Quick Sort"};

    for (int i = 0; i < 3; i++) {
        SortingStrategy *strategy = SortingStrategyFactory::makeSortingStrategy(strategy_name[i]);
        strategy->sort(array, N);
        strategy->print(array, N);
        delete strategy;
    }

    return 0;
}