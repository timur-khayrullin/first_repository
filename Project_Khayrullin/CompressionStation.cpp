#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "CompressionStation.h"
#include "utils.h"
#include <unordered_set>
using namespace std;
int CompressionStation::NextId = 1;

CompressionStation::CompressionStation() {
	this->id = NextId;
	NextId += 1;
}

unordered_set<int> CompressionStation::ChooseIdbyName(const unordered_map<int, CompressionStation>& stations) {
	cout << "������� ��� �������/��������: " << endl;
	string name = InputString();
	unordered_set<int> SetOfId;
	for (const auto& pair : stations) {
		if (pair.second.name == name) {
			SetOfId.insert(pair.first);
		}
	}
	return SetOfId;
}

void CompressionStation::AddStation() {
	cout << "������� �������� �������:" << endl;
	name = InputString();
	cout << "������� ���������� �����:" << endl;
	WorkshopAmount = InputValue<int>(0, 10000);
	cout << "������� ���������� ������� �����:" << endl;
	ProperAmount = InputValue<int>(0,WorkshopAmount);
	cout << "������� ����������� ������������� 0-1:" << endl;
	coefficient = InputValue<double>(0, 1);
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

void CompressionStation::ChangeStation(unordered_map<int, CompressionStation>& stations) {
	unordered_set<int> Ids = ChooseIdbyName(stations);
	for (const auto& i : Ids) {
			cout << "�� ������ ������ �������� ����� " << stations[i].ProperAmount << " �� " << stations[i].WorkshopAmount << endl;
			cout << "������� �������� ����������������� ����� � id=" << i << "?" << endl;
			if (Confirm()){
				cout << "������� ���������� ������� �����:" << endl;
				stations[i].ProperAmount = InputValue<int>(0, stations[i].WorkshopAmount);
				cout << "���������� ������� ����� ��������\n" << endl;
		}
	}
}
void CompressionStation::DeleteStation(unordered_map<int, CompressionStation>& stations) {
	unordered_set<int> Ids = ChooseIdbyName(stations);
	for (auto& i : Ids) {
		cout << "������� ������� ������� � id=" << i << "?" << endl;
		if (Confirm()) {
			stations.erase(i);
			cout << "������� � Id=" << i << "�������\n" << endl;
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
			getline(file, line);
			getline(file, station.name);
			file >> station.WorkshopAmount >> station.ProperAmount >> station.coefficient;
			stations.insert({ id,station });
		}
	}
	file.close();
	cout << "������ ��������� �� �����: " << fileName << endl;
}