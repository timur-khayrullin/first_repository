#include <iostream>
#include <cstdio>
using namespace std;

struct Pipeline {
	string name;
	double length;
	double diameter;
	bool repairing;
};
void AddPipeLine(Pipeline& NewPipe) {
	cout << "������� ��� �����:" << endl;
	cin >> NewPipe.name;
	cout << "������� ����� �����:" << endl;
	cin >> NewPipe.length;
	cout << "������� ������� �����:" << endl;
	cin >> NewPipe.diameter;
	cout << "� ������� ��������? 1/0:" << endl;
	cin >> NewPipe.repairing;
	cout << "����� ���������." << endl;
}
void AddStation() {
	cout << "station added" << endl;
}
void ViewingObjects(string naming) {
	cout << naming;
}
void EditPipeLine(){

}
void EditStation() {

}
void Save() {

}
void Download() {

}
int main()
{
	setlocale(LC_ALL, "RUS");
	int Choice;



	for (;;) {
		cout << "������� 1, ����� �������� �����\n";
		cout << "������� 2, ����� �������� �������� ��\n";
		cout << "������� 3, ����� ����������� ��� �������\n";
		cout << "������� 4, ����� ������������� �����\n";
		cout << "������� 5, ����� ������������� ��\n";
		cout << "������� 6, ����� ���������\n";
		cout << "������� 7, ����� ���������\n";
		cout << "������� 0, ����� �����\n";

		cin >> Choice;

		switch (Choice) {
		case 1: {
			Pipeline Pipe1;
			AddPipeLine(Pipe1);
			break;
		}
		case 2: {
			AddStation();
			break;
		}
		case 3: {
			ViewingObjects(Pipe1);
			break;
		}
		case 4: {
			EditPipeLine();
			break;
		}
		case 5: {
			EditStation();
			break;
		}
		case 6: {
			Save();
			break;
		}
		case 7: {
			Download();
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			break;
		}
		}
		system("pause");
		system("cls");
	};
}
