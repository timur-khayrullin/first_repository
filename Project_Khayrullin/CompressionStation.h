#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

class CompressionStation {
public:
	int WorkshopAmount;
	int ProperAmount;
	double coefficient;
	CompressionStation() : WorkshopAmount(10), ProperAmount(5), coefficient(0.5) {};

	void AddStation(unordered_map<string, CompressionStation>& stations);
	void ViewingStations(const unordered_map<string, CompressionStation> stations);
	void EditStation(unordered_map<string, CompressionStation>& stations, const string& stationName);
	void ChooseStation(unordered_map<string, CompressionStation>& stations);
	void SaveStations(const unordered_map<string, CompressionStation>& stations, string fileName);
	void LoadStations(unordered_map<string, CompressionStation>& stations, string fileName);
};
