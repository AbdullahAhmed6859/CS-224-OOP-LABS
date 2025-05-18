#ifndef VEHICLE_FACTORY
#define VEHICLE_FACTORY

#include "Vehicle.h"
#include <string>
using namespace std;

class VehicleFactory {
public:
    static Vehicle *makeVehicle(string name);
};

#endif