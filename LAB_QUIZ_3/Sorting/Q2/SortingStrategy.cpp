#include "SortingStrategy.h"
#include <iostream>
using std::cout;

void SortingStrategy::print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}