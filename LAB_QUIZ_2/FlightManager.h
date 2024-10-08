// Written by Syed Hammad Ahmed
// YOU MAY NOT MODIFY THIS FILE 

#ifndef FLIGHT_MANAGER_H
#define FLIGHT_MANAGER_H

#include <string>
using namespace std;

class FlightManager {
	private:
		int** distances; // distances from every city to every city
		string* cities; // names of all cities 
		int totalCities; 
		
	public:
		FlightManager(int totalCities);
		~FlightManager();

		void inputCities(); // inputs all city names
		void inputDistances(); // inputs distances from all cities to all other cities	
		void printDistances(); // prints distances from all cities to all other cities 	
		string findNearestCity(string sourceCity); // finds the city having minimum distance from sourceCity 
		
	private:
		// returns the city array index, given the city name
		int getCityIndex(string name);
		// returns the city name, given the array index
		string getCityName(int index);	
};

#endif