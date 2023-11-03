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

	cout << "������� ��� �����:" << endl;
	name = InputString();
	if (pipelines.find(name) != pipelines.end()) {
		cout << "����� � ����� ������ ��� ����������" << endl;
		return;
	}
	Pipeline NewPipe;
	cout << "������� ����� �����:" << endl;
	NewPipe.length = InputDouble(0, 10000000);
	cout << "������� ������� �����:" << endl;
	NewPipe.diameter = InputDouble(0, NewPipe.length);
	cout << "� ������� ���������?" << endl;
	NewPipe.repairing = Confirm();
	pipelines[name] = NewPipe;
	cout << "����� ���������." << endl;
}

void Pipeline::ViewingPipes(const unordered_map<string, Pipeline>& pipelines) {
	cout << "���������� � ������:" << endl;
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		cout << "��� �����: " << pair.first << endl;
		cout << "����� �����: " << pipe.length << endl;
		cout << "������� �����: " << pipe.diameter << endl;
		cout << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
		cout << "--------------------------" << endl;
	}
}
void Pipeline::EditPipeLine(unordered_map<string, Pipeline>& pipelines, const string& pipeName) {
	cout << "������� �������� �������� �����������������?" << endl;
	if (Confirm()) {
		pipelines[pipeName].repairing = !pipelines[pipeName].repairing;
		cout << "�������� ����������������� ����� ��������" << endl;
	}
}
void Pipeline::ChoosePipe(unordered_map<string, Pipeline>& pipelines) {
	string name;
	cout << "������� ��� �����:" << endl;
	name = InputString();
	if (pipelines.find(name) != pipelines.end()) {
		cout << (pipelines[name].repairing ? "� ������ ������ ����� ��������" : "� ������ ������ ����� �� ��������") << endl;
		EditPipeLine(pipelines, name);
	}
	else {
		cout << "����� � ����� ������ �� �������" << endl;
	}
}

void Pipeline::SavePipes(const unordered_map<string, Pipeline>& pipelines, string fileName) {
	ofstream file(fileName);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		file << "�����������:" << endl;
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
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "�����������:") {
			Pipeline pipe;
			getline(file, name);
			file >> pipe.length >> pipe.diameter >> isRepairing;
			pipe.repairing = (isRepairing == "Y" ? true : false);
			pipelines[name] = pipe;
		}
	}
	file.close();
}