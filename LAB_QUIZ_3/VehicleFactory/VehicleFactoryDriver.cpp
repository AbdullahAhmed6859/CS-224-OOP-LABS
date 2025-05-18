#include "Vehicle.h"
#include "VehicleFactory.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter vehicle type: ";
    cin >> name;
    Vehicle *vehicle = VehicleFactory::makeVehicle(name);
    vehicle->move();

    return 0;
}