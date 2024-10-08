#include <iostream>
#include <string>
#include "FlightManager.h"
using namespace std;

// returns the city array index, given the city name
FlightManager::FlightManager(int totalCitiesI) {
	totalCities = totalCitiesI;
	cities = new string[totalCitiesI];
	distances = new int*[totalCitiesI];

	for (int i=0; i<totalCities; i++) {
		distances[i] = new int[totalCitiesI];
		for (int j=0; j<totalCities; j++) 
			distances[i][j] = 0;
	}
}

FlightManager::~FlightManager() {
	delete[] cities;

	for (int i=0; i<totalCities; i++) 
		delete[] distances[i];
	
	delete[] distances;
}

int FlightManager::getCityIndex(string name) {	
	int index = -1;
	for (int i=0; i<totalCities; i++)
		if (cities[i] == name) {
			index = i;
			break;
		}
	return index;	
}

// returns the city name, given the array index
string FlightManager::getCityName(int index) {
	return cities[index];	
}

void FlightManager::inputCities() {
	for (int i=0; i<totalCities; i++) {
		cout << "Enter name of city #" << i+1 << " ";
		cin >> cities[i];
	}
}

void FlightManager::inputDistances() {
	cout << "Input distances from all cities:" << endl << "Enter distances (-1 if no flight):" << endl;
	for (int i=0; i<totalCities; i++) {
		cout << "From " << cities[i] << " to" << endl;

		for (int j=0; j<totalCities; j++) {
			if (i == j) continue;
			cout << cities[j] << ": ";
			cin >> distances[i][j];
		}
		cout << endl;
	}
}

void FlightManager::printDistances() {
	cout << "Flights:" << endl;

	for (int i=0; i<totalCities; i++) {
		cout << "From " << cities[i] << " to" << endl;

		for (int j=0; j<totalCities; j++) {
			if (i == j) continue;
			cout << "        " << cities[j] << ": " << distances[i][j] << endl;
		}
		cout << endl;
	}
}

string FlightManager::findNearestCity(string sourceCity) {
	int sourceI = getCityIndex(sourceCity);
	int dist = 1073741824;
	int minIndex = -1;

	for (int j=0; j<totalCities; j++) {
		if (j==sourceI) continue;
		if (dist != -1 && dist > distances[sourceI][j]) {
			dist = distances[sourceI][j];
			minIndex = j;
		}
	}
	
	return (minIndex == -1) ? "" : getCityName(minIndex);
}