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
void filterPipe(const unordered_map<string, Pipeline>& pipelines) {
	string wish;
	string name_value;
	bool repairing_value;
	cout << "\n1.����������� �� �����" << "\n" << "2.����������� �� �������� �������" << endl;
	if (InputInt(1, 2) == 1) {
		cout << "������� ��� : " << endl;
		name_value = InputString();
		for (const auto& pair : pipelines) {
			if (pair.first == name_value) {
				const Pipeline& pipe = pair.second;
				cout << "��� �����: " << pair.first << endl;
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
				cout << "��� �����: " << pair.first << endl;
				cout << "����� �����: " << pipe.length << endl;
				cout << "������� �����: " << pipe.diameter << endl;
				cout << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
				cout << "--------------------------" << endl;
			}
		}
	}
}
void filterStation(const unordered_map<string, CompressionStation> stations) {
	string wish;
	string name_value;
	double percent_value;
	cout << "\n1.����������� �� �����" << "\n" << "2.����������� �� �������� ����������������� �����" << endl;
	if (InputInt(1, 2) == 1) {
		cout << "������� ��� : " << endl;
		name_value = InputString();
		for (const auto& pair : stations) {
			if (pair.first == name_value) {
				const CompressionStation& station = pair.second;
				cout << "��� �������: " << pair.first << endl;
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
			cout << ((station.WorkshopAmount - station.ProperAmount) * 100.0 / station.WorkshopAmount)  << endl;
			if (((station.WorkshopAmount - station.ProperAmount) * 100.0 / station.WorkshopAmount) == percent_value) {
				cout << "��� �������: " << pair.first << endl;
				cout << "���������� �����: " << station.WorkshopAmount << endl;
				cout << "���������� ������� �����: " << station.ProperAmount << endl;
				cout << "����������� �������������: " << station.coefficient << endl;
				cout << "--------------------------" << endl;
			}
		}
	}
}