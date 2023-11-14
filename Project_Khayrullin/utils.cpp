#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "utils.h"
#include "Pipeline.h"
#include "CompressionStation.h"
using namespace std;

bool Confirm()
{
	string wish;
	cout << "Y/N?" << endl;
	while (1)
	{
		if (cin >> wish)
		{
			if (wish == "Y") {
				return true;
			}
			else if (wish == "N") {
				return false;
			}
		}
		cout << "�� ����� �������� ��������. ��������� �����" << endl;
	}
}
int InputInt(int min = 0, int max = 1000)
{
	int x;
	while (!(cin >> x) || x > max || x < min) {
		cout << "�������� ��������. ���������� ��� ���:" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return x;
}
double InputDouble(int min = 0, double max = 10000000) {
	double x;
	while (!(cin >> x) || x > max || x < min) {
		cout << "�������� ��������. ���������� ��� ���:" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return x;
}
string InputString() {
	string x;
	for (;;) {
		getline(cin, x);
		if (!x.empty()) {
			return x;
		}
	}
	return x;
}
void filterPipe(const unordered_map<int, Pipeline>& pipelines) {
	string name_value;
	bool repairing_value;
	cout << "\n1.����������� �� �����" << "\n" << "2.����������� �� �������� �������" << endl;
	if (InputInt(1, 2) == 1) {
		cout << "������� ��� : " << endl;
		name_value = InputString();
		for (const auto& pair : pipelines) {
			const Pipeline& pipe = pair.second;
			if (pipe.name == name_value) {
				cout << "Id �����: " << pair.first << endl;
				cout << "��� �����: " << pipe.name << endl;
				cout << "����� �����: " << pipe.length << endl;
				cout << "������� �����: " << pipe.diameter << endl;
				cout << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
				cout << "--------------------------" << endl;
			}
		}
	}
	else {
		cout << "\n������� �������� ����������������� : " << endl;
		repairing_value = Confirm();
		for (const auto& pair : pipelines) {
			const Pipeline& pipe = pair.second;
			if (pipe.repairing == repairing_value) {
				cout << "Id �����: " << pair.first << endl;
				cout << "��� �����: " << pipe.name << endl;
				cout << "����� �����: " << pipe.length << endl;
				cout << "������� �����: " << pipe.diameter << endl;
				cout << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
				cout << "--------------------------" << endl;
			}
		}
	}
}
void filterStation(const unordered_map<int, CompressionStation> stations) {
	string name_value;
	double percent_value;
	cout << "\n1.����������� �� �����" << "\n" << "2.����������� �� �������� ����������������� �����" << endl;
	if (InputInt(1, 2) == 1) {
		cout << "������� ��� : " << endl;
		name_value = InputString();
		for (const auto& pair : stations) {
			const CompressionStation& station = pair.second;
			if (station.name == name_value) {
				cout << "Id �������: " << pair.first << endl;
				cout << "��� �������: " << station.name << endl;
				cout << "���������� �����: " << station.WorkshopAmount << endl;
				cout << "���������� ������� �����: " << station.ProperAmount << endl;
				cout << "����������� �������������: " << station.coefficient << endl;
				cout << "--------------------------" << endl;
			}
		}
	}
	else {
		cout <<"������� ������� ����������������� �����: "<< endl;
		percent_value = InputDouble (0, 100);
		for (const auto& pair : stations) {
			const CompressionStation& station = pair.second;
			if (((station.WorkshopAmount - station.ProperAmount) * 100.0 / station.WorkshopAmount) == percent_value) {
				cout << "Id �������: " << pair.first << endl;
				cout << "��� �������: " << station.name << endl;
				cout << "���������� �����: " << station.WorkshopAmount << endl;
				cout << "���������� ������� �����: " << station.ProperAmount << endl;
				cout << "����������� �������������: " << station.coefficient << endl;
				cout << "--------------------------" << endl;
			}
		}
	}
}