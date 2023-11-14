#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipeline.h"
#include "utils.h"
#include <unordered_set>
using namespace std;
int Pipeline::NextId = 0;

Pipeline::Pipeline() {
	this->id = NextId;
	NextId += 1;
}
unordered_set<int> Pipeline::ChooseIdbyName(const unordered_map<int, Pipeline>& pipelines) {
	cout << "Введите имя объекта/объектов: " << endl;
	string name = InputString();
	unordered_set<int> SetOfId;
	for (const auto& pair : pipelines) {
		if (pair.second.name == name) {
			SetOfId.insert(pair.first);
		}
	}
	return SetOfId;
}
void Pipeline::AddPipeLine()
{
	cout << "Введите имя трубы:" << endl;
	name = InputString();
	cout << "Введите длину трубы:" << endl;
	length = InputValue<double>(0, 100000000);
	cout << "Введите диаметр трубы:" << endl;
	diameter = InputValue<double>(0, length);
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

void Pipeline::ChangePipe(unordered_map<int, Pipeline>& pipelines) {
	unordered_set<int> Ids = ChooseIdbyName(pipelines);
	for (const auto& i : Ids) {
		cout << (pipelines[i].repairing ? "В данный момент труба работает" : "В данный момент труба НЕ работает") << endl;
		cout << "Желаете изменить работоспособность трубы с id=" << i << "?" << endl;
		if (Confirm()) {
			pipelines[i].repairing = !pipelines[i].repairing;
			cout << "Значение работоспособности трубы изменено\n" << endl;
		}
	}
}
void Pipeline::DeletePipe(unordered_map<int, Pipeline>& pipelines) {
	unordered_set<int> Ids = ChooseIdbyName(pipelines);
	for (const auto& i : Ids) {
		cout << "Желаете удалить трубу с id=" << i << "?" << endl;
		if (Confirm()) {
			pipelines.erase(i);
			cout << "Труба с Id=" << i << "удалена\n" << endl;
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
	int id;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "Трубопровод:") {
			Pipeline pipe;
			file >> id;
			getline(file, line);
			getline(file, pipe.name);
			file >> pipe.length >> pipe.diameter >> isRepairing;
			pipe.repairing = (isRepairing == "Y" ? true : false);
			pipelines.insert({ id, pipe});
		}
	}
	file.close();
}