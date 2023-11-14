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
	cout << "Введите название станции:" << endl;
	name = InputString();
	cout << "Введите количество цехов:" << endl;
	WorkshopAmount = InputInt(0, 1000);
	cout << "Введите количество рабочих цехов:" << endl;
	ProperAmount = InputInt(0,WorkshopAmount);
	cout << "Введите коэффициент эффективности 0-1:" << endl;
	coefficient = InputDouble(0, 1);
}

void CompressionStation::ViewingStations(const unordered_map<int, CompressionStation> stations) {
	cout << endl << endl << "ИНФОРМАЦИЯ О СТАНЦИЯХ:" << endl;
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		cout << "Id станции: " << pair.first << endl;
		cout << "Имя станции: " << station.name << endl;
		cout << "Количество цехов: " << station.WorkshopAmount << endl;
		cout << "Количество рабочих цехов: " << station.ProperAmount << endl;
		cout << "Коэффициент эффективности: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}


//void CompressionStation::EditStation(unordered_map<int, CompressionStation>& stations, const string& stationName) {
//	cout << "Желаете изменить количество рабочих цехов?" << endl;
//	if (Confirm()) {
//		cout << "Введите количество рабочих цехов:" << endl;
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
//	cout << "Введите название станции:" << endl;
//	name = InputString();
//	if (stations.find(name) != stations.end()) {
//		cout << "На данный момент работает цехов " << stations[name].ProperAmount << " из " << stations[name].WorkshopAmount << endl;
//		EditStation(stations, name);
//	}
//	else {
//		cout << "Станции с таким именем не найдено" << endl;
//	}
//}
void CompressionStation::ChangeStation(unordered_map<int, CompressionStation>& stations) {
	string name;
	cout << "Введите название станции:" << endl;
	for ( auto& pair : stations) {
		 CompressionStation& station = pair.second;
		if (station.name == InputString()) {
			cout << "На данный момент работает цехов " << station.ProperAmount << " из " << station.WorkshopAmount << endl;
			cout << "Введите количество рабочих цехов:" << endl;
			station.ProperAmount = InputInt(0, station.WorkshopAmount);
		}
		else {
			cout << "Станции с таким именем не найдено" << endl;
		}
	}
}

void CompressionStation::SaveStations(const unordered_map<int, CompressionStation>& stations, string fileName) {
	ofstream file(fileName, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		file << "Станция:" << endl;
		file << pair.first << endl;
		file << station.name << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "Данные сохранены в файл: " << fileName << endl;
}


void CompressionStation::LoadStations(unordered_map<int, CompressionStation>& stations, string fileName) {
	string line;
	int id;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "Станция:") {
			CompressionStation station;
			file >> id;
			getline(file, station.name);
			file >> station.WorkshopAmount >> station.ProperAmount >> station.coefficient;
			stations[id] = station;
		}
	}
	file.close();
	cout << "Данные загружены из файла: " << fileName << endl;
}