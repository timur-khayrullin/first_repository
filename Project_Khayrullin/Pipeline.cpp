#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipeline.h"
#include "utils.h"
using namespace std;
int Pipeline::NextId = 0;

Pipeline::Pipeline() {
	this->id = NextId;
	NextId += 1;
}
void Pipeline::AddPipeLine()
{
	cout << "Введите имя трубы:" << endl;
	name = InputString();
	cout << "Введите длину трубы:" << endl;
	length = InputDouble(0, 10000000);
	cout << "Введите диаметр трубы:" << endl;
	diameter = InputDouble(0, length);
	cout << "В рабочем состоянии?" << endl;
	repairing = Confirm();	
}

void Pipeline::ViewingPipes(const unordered_map<int, Pipeline>& pipelines) {
	cout << "ИНФОРМАЦИЯ О ТРУБАХ:" << endl;
	for (const auto& pair : pipelines) {
		cout << "Id трубы: " << pair.first << endl;
		cout << "Имя трубы: " << pair.second.name << endl;
		cout << "Длина трубы: " << pair.second.length << endl;
		cout << "Диаметр трубы: " << pair.second.diameter << endl;
		cout << "В рабочем состоянии: " << (pair.second.repairing ? "Да" : "Нет") << endl;
		cout << "--------------------------" << endl;
	}
}
//void Pipeline::EditPipeLine(unordered_map<int, Pipeline>& pipelines, const string& pipeName) {
//	cout << "Желаете изменить значение работоспособности?" << endl;
//	if (Confirm()) {
//		pipelines[pipeName].repairing = !pipelines[pipeName].repairing;
//		cout << "Значение работоспособности трубы изменено" << endl;
//	}
//}
//void Pipeline::ChoosePipe(unordered_map<int, Pipeline>& pipelines) {
//	string name;
//	cout << "Введите имя трубы:" << endl;
//	name = InputString();
//	if (pipelines.find(name) != pipelines.end()) {
//		cout << (pipelines[name].repairing ? "В данный момент труба работает" : "В данный момент труба НЕ работает") << endl;
//		EditPipeLine(pipelines, name);
//	}
//	else {
//		cout << "Трубы с таким именем не найдено" << endl;
//	}
//}
void Pipeline::ChangePipe(unordered_map<int, Pipeline>& pipelines) {
	string name;
	cout << "Введите название трубы :" << endl;
	for (auto& pair : pipelines) {
		Pipeline& pipe = pair.second;
		if (pipe.name == InputString()) {
			cout << (pipe.repairing ? "В данный момент труба работает" : "В данный момент труба НЕ работает") << endl;
			cout << "Желаете изменить значение работоспособности?" << endl;
			if (Confirm()) {
				pipe.repairing = !pipe.repairing;
				cout << "Значение работоспособности трубы изменено" << endl;
			}
		}
		else {
			cout << "Трубы с таким именем не найдено" << endl;
		}
	}
}

void Pipeline::SavePipes(const unordered_map<int, Pipeline>& pipelines, string fileName) {
	ofstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		file << "Трубопровод:" << endl;
		file << pair.first << endl;
		file << pipe.name << endl;
		file << pipe.length << endl;
		file << pipe.diameter << endl;
		file << (pipe.repairing ? "Y" : "N") << endl;
	}
	file.close();
}
void Pipeline::LoadPipes(unordered_map<int, Pipeline>& pipelines, string fileName) {
	string line, isRepairing;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "Трубопровод:") {
			Pipeline pipe;
			file >> id;
			getline(file, pipe.name);
			file >> pipe.length >> pipe.diameter >> isRepairing;
			pipe.repairing = (isRepairing == "Y" ? true : false);
			pipelines[id] = pipe;
		}
	}
	file.close();
}