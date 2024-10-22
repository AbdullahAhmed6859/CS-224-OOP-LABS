#include <iostream>
#include "Bird.h"
using std::cout;
using std::endl;

Bird::Bird() {
    cout << "Bird created" << endl;
}

Bird::~Bird() {
    cout << "Bird removed" << endl;
}

void Bird::fly(){
    cout << "This bird can fly." << endl;
}