#include "VehicleFactory.h"
#include "Boat.h"
#include "Car.h"
#include "Vehicle.h"

Vehicle *VehicleFactory::makeVehicle(string name) {
    Vehicle *ptr;
    if (name == "boat") {
        ptr = new Boat;
    } else if (name == "car") {
        ptr = new Car;
    }
    return ptr;
}
