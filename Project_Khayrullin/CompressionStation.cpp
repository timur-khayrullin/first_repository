#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "CompressionStation.h"
#include "utils.h"
using namespace std;

void CompressionStation::AddStation(unordered_map<string, CompressionStation>& stations) {
	string name;

	cout << "������� �������� �������:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
		cout << "����� � ����� ������ ��� ����������" << endl;
		return;
	}
	CompressionStation NewStation;
	cout << "������� ���������� �����:" << endl;
	NewStation.WorkshopAmount = InputInt(0, 1000);
	cout << "������� ���������� ������� �����:" << endl;
	NewStation.ProperAmount = InputInt(0, NewStation.WorkshopAmount);
	cout << "������� ����������� ������������� 0-1:" << endl;
	NewStation.coefficient = InputDouble(0, 1);
	stations[name] = NewStation;
	cout << "������� ���������." << endl;

}

void CompressionStation::ViewingStations(const unordered_map<string, CompressionStation> stations) {
	cout << endl << endl << "���������� � ��������:" << endl;
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		cout << "��� �������: " << pair.first << endl;
		cout << "���������� �����: " << station.WorkshopAmount << endl;
		cout << "���������� ������� �����: " << station.ProperAmount << endl;
		cout << "����������� �������������: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}


void CompressionStation::EditStation(unordered_map<string, CompressionStation>& stations, const string& stationName) {
	cout << "������� �������� ���������� ������� �����?" << endl;
	if (Confirm()) {
		cout << "������� ���������� ������� �����:" << endl;
		stations[stationName].ProperAmount = InputInt(0, stations[stationName].WorkshopAmount);
	}
}

void CompressionStation::ChooseStation(unordered_map<string, CompressionStation>& stations) {
	string name;
	cout << "������� �������� �������:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
		cout << "�� ������ ������ �������� ����� " << stations[name].ProperAmount << " �� " << stations[name].WorkshopAmount << endl;
		EditStation(stations, name);
	}
	else {
		cout << "������� � ����� ������ �� �������" << endl;
	}
}

void CompressionStation::SaveStations(const unordered_map<string, CompressionStation>& stations, string fileName) {
	ofstream file(fileName, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		file << "�������:" << endl;
		file << pair.first << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "������ ��������� � ����: " << fileName << endl;
}


void CompressionStation::LoadStations(unordered_map<string, CompressionStation>& stations, string fileName) {
	string name, line;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "�������:") {
			CompressionStation station;
			getline(file, name);
			file >> station.WorkshopAmount >> station.ProperAmount >> station.coefficient;
			stations[name] = station;
		}
	}
	file.close();
	cout << "������ ��������� �� �����: " << fileName << endl;
}