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
	cout << "������� ��� �����:" << endl;
	name = InputString();
	cout << "������� ����� �����:" << endl;
	length = InputDouble(0, 10000000);
	cout << "������� ������� �����:" << endl;
	diameter = InputDouble(0, length);
	cout << "� ������� ���������?" << endl;
	repairing = Confirm();	
}

void Pipeline::ViewingPipes(const unordered_map<int, Pipeline>& pipelines) {
	cout << "���������� � ������:" << endl;
	for (const auto& pair : pipelines) {
		cout << "Id �����: " << pair.first << endl;
		cout << "��� �����: " << pair.second.name << endl;
		cout << "����� �����: " << pair.second.length << endl;
		cout << "������� �����: " << pair.second.diameter << endl;
		cout << "� ������� ���������: " << (pair.second.repairing ? "��" : "���") << endl;
		cout << "--------------------------" << endl;
	}
}
//void Pipeline::EditPipeLine(unordered_map<int, Pipeline>& pipelines, const string& pipeName) {
//	cout << "������� �������� �������� �����������������?" << endl;
//	if (Confirm()) {
//		pipelines[pipeName].repairing = !pipelines[pipeName].repairing;
//		cout << "�������� ����������������� ����� ��������" << endl;
//	}
//}
//void Pipeline::ChoosePipe(unordered_map<int, Pipeline>& pipelines) {
//	string name;
//	cout << "������� ��� �����:" << endl;
//	name = InputString();
//	if (pipelines.find(name) != pipelines.end()) {
//		cout << (pipelines[name].repairing ? "� ������ ������ ����� ��������" : "� ������ ������ ����� �� ��������") << endl;
//		EditPipeLine(pipelines, name);
//	}
//	else {
//		cout << "����� � ����� ������ �� �������" << endl;
//	}
//}
void Pipeline::ChangePipe(unordered_map<int, Pipeline>& pipelines) {
	string name;
	cout << "������� �������� ����� :" << endl;
	for (auto& pair : pipelines) {
		Pipeline& pipe = pair.second;
		if (pipe.name == InputString()) {
			cout << (pipe.repairing ? "� ������ ������ ����� ��������" : "� ������ ������ ����� �� ��������") << endl;
			cout << "������� �������� �������� �����������������?" << endl;
			if (Confirm()) {
				pipe.repairing = !pipe.repairing;
				cout << "�������� ����������������� ����� ��������" << endl;
			}
		}
		else {
			cout << "����� � ����� ������ �� �������" << endl;
		}
	}
}

void Pipeline::SavePipes(const unordered_map<int, Pipeline>& pipelines, string fileName) {
	ofstream file(fileName);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		file << "�����������:" << endl;
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
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "�����������:") {
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