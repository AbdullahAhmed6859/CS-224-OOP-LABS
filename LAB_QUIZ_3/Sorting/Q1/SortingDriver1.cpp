#include <iostream>
#include <string>
#include "SortingStrategy.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
using namespace std;

#define N 10

int main(){
	int array[] = {9, 7, 5, 3, 2, 1, 4, 8, 6, 0};

	SortingStrategy* strategy[] = {new BubbleSort, new SelectionSort, new QuickSort};
	for (int i=0; i<3; i++) {
		strategy[i]->sort(array, N);
		strategy[i]->print(array, N);
	}	
	
	for (int i=0; i<3; i++) {
		delete strategy[i];
	}	
	
	return 0;
}