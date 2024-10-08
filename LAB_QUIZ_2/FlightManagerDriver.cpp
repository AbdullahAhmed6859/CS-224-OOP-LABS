#include <iostream>
#include <string>
#include "FlightManager.h"
using namespace std;

int main(){
	const string sourceCity = "Karachi";
	string nearestCity = "";
    string mostApproachableCity = "";
	int totalCities = 0;
	
	cout << "Enter total cities: ";
	cin >> totalCities;
	
	FlightManager habibAirlines(totalCities);
	
	habibAirlines.inputCities(); // inputs all city names
	habibAirlines.inputDistances(); // inputs distances from all cities to all other cities	
	
	habibAirlines.printDistances(); // prints distances from all cities to all other cities	
 
	nearestCity = habibAirlines.findNearestCity(sourceCity); // finds the city having minimum distance from sourceCity 
	cout << "hello" << endl;
	cout << "City nearest to " << sourceCity << " is : " << nearestCity << endl;
	
	return 0;
}