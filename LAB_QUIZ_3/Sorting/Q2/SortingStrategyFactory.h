#ifndef SORTINGSTRATEGYFACTORY_H
#define SORTINGSTRATEGYFACTORY_H
#include "SortingStrategy.h"
#include <string>
using std::string;

class SortingStrategyFactory {
public:
    static SortingStrategy *makeSortingStrategy(const string &algo);
};
#endif