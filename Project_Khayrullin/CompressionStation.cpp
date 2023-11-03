#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "CompressionStation.h"
#include "utils.h"
using namespace std;

void CompressionStation::AddStation(unordered_map<string, CompressionStation>& stations) {
	string name;

	cout << "Введите название станции:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
		cout << "Труба с таким именем уже существует" << endl;
		return;
	}
	CompressionStation NewStation;
	cout << "Введите количество цехов:" << endl;
	NewStation.WorkshopAmount = InputInt(0, 1000);
	cout << "Введите количество рабочих цехов:" << endl;
	NewStation.ProperAmount = InputInt(0, NewStation.WorkshopAmount);
	cout << "Введите коэффициент эффективности 0-1:" << endl;
	NewStation.coefficient = InputDouble(0, 1);
	stations[name] = NewStation;
	cout << "Станция добавлена." << endl;

}

void CompressionStation::ViewingStations(const unordered_map<string, CompressionStation> stations) {
	cout << endl << endl << "ИНФОРМАЦИЯ О СТАНЦИЯХ:" << endl;
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		cout << "Имя станции: " << pair.first << endl;
		cout << "Количество цехов: " << station.WorkshopAmount << endl;
		cout << "Количество рабочих цехов: " << station.ProperAmount << endl;
		cout << "Коэффициент эффективности: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}


void CompressionStation::EditStation(unordered_map<string, CompressionStation>& stations, const string& stationName) {
	cout << "Желаете изменить количество рабочих цехов?" << endl;
	if (Confirm()) {
		cout << "Введите количество рабочих цехов:" << endl;
		stations[stationName].ProperAmount = InputInt(0, stations[stationName].WorkshopAmount);
	}
}

void CompressionStation::ChooseStation(unordered_map<string, CompressionStation>& stations) {
	string name;
	cout << "Введите название станции:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
		cout << "На данный момент работает цехов " << stations[name].ProperAmount << " из " << stations[name].WorkshopAmount << endl;
		EditStation(stations, name);
	}
	else {
		cout << "Станции с таким именем не найдено" << endl;
	}
}

void CompressionStation::SaveStations(const unordered_map<string, CompressionStation>& stations, string fileName) {
	ofstream file(fileName, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		file << "Станция:" << endl;
		file << pair.first << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "Данные сохранены в файл: " << fileName << endl;
}


void CompressionStation::LoadStations(unordered_map<string, CompressionStation>& stations, string fileName) {
	string name, line;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "Станция:") {
			CompressionStation station;
			getline(file, name);
			file >> station.WorkshopAmount >> station.ProperAmount >> station.coefficient;
			stations[name] = station;
		}
	}
	file.close();
	cout << "Данные загружены из файла: " << fileName << endl;
}