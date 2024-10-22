#include <iostream>
#include "Animal.h"
using std::cout;
using std::endl;

Animal::Animal() {
    cout << "Animal Created" << endl;
}

Animal::~Animal() {
    cout << "Animal removed" << endl;
}

void Animal::eat() {
    cout << "This animal eats food." << endl;
}

void Animal::sleep() {
    cout << "This animal sleeps." << endl;
}
