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
	cout << "Введите имя объекта/объектов: " << endl;
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
	cout << "Введите название станции:" << endl;
	name = InputString();
	cout << "Введите количество цехов:" << endl;
	WorkshopAmount = InputValue<int>(0, 10000);
	cout << "Введите количество рабочих цехов:" << endl;
	ProperAmount = InputValue<int>(0,WorkshopAmount);
	cout << "Введите коэффициент эффективности 0-1:" << endl;
	coefficient = InputValue<double>(0, 1);
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

void CompressionStation::ChangeStation(unordered_map<int, CompressionStation>& stations) {
	unordered_set<int> Ids = ChooseIdbyName(stations);
	for (const auto& i : Ids) {
			cout << "На данный момент работает цехов " << stations[i].ProperAmount << " из " << stations[i].WorkshopAmount << endl;
			cout << "Желаете изменить работоспособность трубы с id=" << i << "?" << endl;
			if (Confirm()){
				cout << "Введите количество рабочих цехов:" << endl;
				stations[i].ProperAmount = InputValue<int>(0, stations[i].WorkshopAmount);
				cout << "Количество рабочих цехов изменено\n" << endl;
		}
	}
}
void CompressionStation::DeleteStation(unordered_map<int, CompressionStation>& stations) {
	unordered_set<int> Ids = ChooseIdbyName(stations);
	for (auto& i : Ids) {
		cout << "Желаете удалить станцию с id=" << i << "?" << endl;
		if (Confirm()) {
			stations.erase(i);
			cout << "Станция с Id=" << i << "удалена\n" << endl;
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
			getline(file, line);
			getline(file, station.name);
			file >> station.WorkshopAmount >> station.ProperAmount >> station.coefficient;
			stations.insert({ id,station });
		}
	}
	file.close();
	cout << "Данные загружены из файла: " << fileName << endl;
}