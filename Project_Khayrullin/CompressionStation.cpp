#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "CompressionStation.h"
#include "utils.h"
using namespace std;
int CompressionStation::NextId = 1;

CompressionStation::CompressionStation() {
	this->id = NextId;
	NextId += 1;
}


void CompressionStation::AddStation() {
	cout << "������� �������� �������:" << endl;
	name = InputString();
	cout << "������� ���������� �����:" << endl;
	WorkshopAmount = InputInt(0, 1000);
	cout << "������� ���������� ������� �����:" << endl;
	ProperAmount = InputInt(0,WorkshopAmount);
	cout << "������� ����������� ������������� 0-1:" << endl;
	coefficient = InputDouble(0, 1);
}

void CompressionStation::ViewingStations(const unordered_map<int, CompressionStation> stations) {
	cout << endl << endl << "���������� � ��������:" << endl;
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		cout << "Id �������: " << pair.first << endl;
		cout << "��� �������: " << station.name << endl;
		cout << "���������� �����: " << station.WorkshopAmount << endl;
		cout << "���������� ������� �����: " << station.ProperAmount << endl;
		cout << "����������� �������������: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}


//void CompressionStation::EditStation(unordered_map<int, CompressionStation>& stations, const string& stationName) {
//	cout << "������� �������� ���������� ������� �����?" << endl;
//	if (Confirm()) {
//		cout << "������� ���������� ������� �����:" << endl;
//		for (const auto& pair : stations) {
//			const CompressionStation& station = pair.second;
//			if (station.name == stationName) {
//				station.ProperAmount == InputInt(0, station.WorkshopAmount);
//			}
//		}
//	}
//}
//
//void CompressionStation::ChooseStation(unordered_map<int, CompressionStation>& stations) {
//	string name;
//	cout << "������� �������� �������:" << endl;
//	name = InputString();
//	if (stations.find(name) != stations.end()) {
//		cout << "�� ������ ������ �������� ����� " << stations[name].ProperAmount << " �� " << stations[name].WorkshopAmount << endl;
//		EditStation(stations, name);
//	}
//	else {
//		cout << "������� � ����� ������ �� �������" << endl;
//	}
//}
void CompressionStation::ChangeStation(unordered_map<int, CompressionStation>& stations) {
	string name;
	cout << "������� �������� �������:" << endl;
	for ( auto& pair : stations) {
		 CompressionStation& station = pair.second;
		if (station.name == InputString()) {
			cout << "�� ������ ������ �������� ����� " << station.ProperAmount << " �� " << station.WorkshopAmount << endl;
			cout << "������� ���������� ������� �����:" << endl;
			station.ProperAmount = InputInt(0, station.WorkshopAmount);
		}
		else {
			cout << "������� � ����� ������ �� �������" << endl;
		}
	}
}

void CompressionStation::SaveStations(const unordered_map<int, CompressionStation>& stations, string fileName) {
	ofstream file(fileName, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		file << "�������:" << endl;
		file << pair.first << endl;
		file << station.name << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "������ ��������� � ����: " << fileName << endl;
}


void CompressionStation::LoadStations(unordered_map<int, CompressionStation>& stations, string fileName) {
	string line;
	int id;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "�������:") {
			CompressionStation station;
			file >> id;
			getline(file, station.name);
			file >> station.WorkshopAmount >> station.ProperAmount >> station.coefficient;
			stations[id] = station;
		}
	}
	file.close();
	cout << "������ ��������� �� �����: " << fileName << endl;
}