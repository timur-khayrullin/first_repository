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
	cout << "������� ��� �������/��������: " << endl;
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
	cout << "������� ��� �����:" << endl;
	name = InputString();
	cout << "������� ����� �����:" << endl;
	length = InputValue<double>(0, 100000000);
	cout << "������� ������� �����:" << endl;
	diameter = InputValue<double>(0, length);
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

void Pipeline::ChangePipe(unordered_map<int, Pipeline>& pipelines) {
	unordered_set<int> Ids = ChooseIdbyName(pipelines);
	for (const auto& i : Ids) {
		cout << (pipelines[i].repairing ? "� ������ ������ ����� ��������" : "� ������ ������ ����� �� ��������") << endl;
		cout << "������� �������� ����������������� ����� � id=" << i << "?" << endl;
		if (Confirm()) {
			pipelines[i].repairing = !pipelines[i].repairing;
			cout << "�������� ����������������� ����� ��������\n" << endl;
		}
	}
}
void Pipeline::DeletePipe(unordered_map<int, Pipeline>& pipelines) {
	unordered_set<int> Ids = ChooseIdbyName(pipelines);
	for (const auto& i : Ids) {
		cout << "������� ������� ����� � id=" << i << "?" << endl;
		if (Confirm()) {
			pipelines.erase(i);
			cout << "����� � Id=" << i << "�������\n" << endl;
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
	int id;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "�����������:") {
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