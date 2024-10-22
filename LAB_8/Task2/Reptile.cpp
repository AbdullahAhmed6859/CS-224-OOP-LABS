#include <iostream>
#include "Reptile.h"
using std::cout;
using std::endl;

Reptile::Reptile() {
	cout << "Reptile created" << endl;
} 

Reptile::~Reptile() {
    cout << "Reptile removed" << endl;
}

void Reptile::crawl() {
    cout << "This reptile crawls." << endl;
}