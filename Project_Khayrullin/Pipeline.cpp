#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipeline.h"
#include "utils.h"
using namespace std;

void Pipeline::AddPipeLine(unordered_map<string, Pipeline>& pipelines)
{
	string name;

	cout << "Введите имя трубы:" << endl;
	name = InputString();
	if (pipelines.find(name) != pipelines.end()) {
		cout << "Труба с таким именем уже существует" << endl;
		return;
	}
	Pipeline NewPipe;
	cout << "Введите длину трубы:" << endl;
	NewPipe.length = InputDouble(0, 10000000);
	cout << "Введите диаметр трубы:" << endl;
	NewPipe.diameter = InputDouble(0, NewPipe.length);
	cout << "В рабочем состоянии?" << endl;
	NewPipe.repairing = Confirm();
	pipelines[name] = NewPipe;
	cout << "Труба добавлена." << endl;
}

void Pipeline::ViewingPipes(const unordered_map<string, Pipeline>& pipelines) {
	cout << "ИНФОРМАЦИЯ О ТРУБАХ:" << endl;
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		cout << "Имя трубы: " << pair.first << endl;
		cout << "Длина трубы: " << pipe.length << endl;
		cout << "Диаметр трубы: " << pipe.diameter << endl;
		cout << "В рабочем состоянии: " << (pipe.repairing ? "Да" : "Нет") << endl;
		cout << "--------------------------" << endl;
	}
}
void Pipeline::EditPipeLine(unordered_map<string, Pipeline>& pipelines, const string& pipeName) {
	cout << "Желаете изменить значение работоспособности?" << endl;
	if (Confirm()) {
		pipelines[pipeName].repairing = !pipelines[pipeName].repairing;
		cout << "Значение работоспособности трубы изменено" << endl;
	}
}
void Pipeline::ChoosePipe(unordered_map<string, Pipeline>& pipelines) {
	string name;
	cout << "Введите имя трубы:" << endl;
	name = InputString();
	if (pipelines.find(name) != pipelines.end()) {
		cout << (pipelines[name].repairing ? "В данный момент труба работает" : "В данный момент труба НЕ работает") << endl;
		EditPipeLine(pipelines, name);
	}
	else {
		cout << "Трубы с таким именем не найдено" << endl;
	}
}

void Pipeline::SavePipes(const unordered_map<string, Pipeline>& pipelines, string fileName) {
	ofstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		file << "Трубопровод:" << endl;
		file << pair.first << endl;
		file << pipe.length << endl;
		file << pipe.diameter << endl;
		file << (pipe.repairing ? "Y" : "N") << endl;
	}
	file.close();
}
void Pipeline::LoadPipes(unordered_map<string, Pipeline>& pipelines, string fileName) {
	string name, line, isRepairing;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "Трубопровод:") {
			Pipeline pipe;
			getline(file, name);
			file >> pipe.length >> pipe.diameter >> isRepairing;
			pipe.repairing = (isRepairing == "Y" ? true : false);
			pipelines[name] = pipe;
		}
	}
	file.close();
}