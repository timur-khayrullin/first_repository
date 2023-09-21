#include <iostream>
#include <fstream>
using namespace std;

const int MaxPipelines = 50;
const int MaxStations = 50;

struct Pipeline {
	string name;
	double length;
	double diameter;
	bool repairing;
};
struct CompressionStation {
	string name;
	int WorkshopAmount;
	int ProperAmount;
	float coefficient;
};

void AddPipeLine(Pipeline pipelines[], int& PipeNumber)
{
	string isRepairing;
	if (PipeNumber >= MaxPipelines) {
		cout << "���������� ������������ ���������� �������������." << endl;
		return;
	}

	Pipeline& NewPipe = pipelines[PipeNumber];

	cout << "������� ��� �����:" << endl;
	cin >> NewPipe.name;
	cout << "������� ����� �����:" << endl;
	cin >> NewPipe.length;
	cout << "������� ������� �����:" << endl;
	cin >> NewPipe.diameter;
	do {
		cout << "� ������� ���������? Y/N:" << endl;
		cin >> isRepairing;
		if (isRepairing == "Y") {
			NewPipe.repairing = 1;
		}
		else if (isRepairing == "N") {
			NewPipe.repairing = 0;
		}
		else {
			cout << "�� ����� �������� ��������. ��������� �����" << endl;
		}
	} while (isRepairing != "Y" && isRepairing != "N");
	cout << "����� ���������." << endl;
	PipeNumber++;
}
void AddStation(CompressionStation stations[], int& StationNumber) {
	if (StationNumber >= MaxStations) {
		cout << "���������� ������������ ���������� �������" << endl;
		return;
	}

	CompressionStation& NewStation = stations[StationNumber];

	cout << "������� �������� �������:" << endl;
	cin >> NewStation.name;
	cout << "������� ���������� �����:" << endl;
	cin >> NewStation.WorkshopAmount;
	cout << "������� ���������� ������� �����:" << endl;
	cin >> NewStation.ProperAmount;
	cout << "������� ����������� ������������� 0-1:" << endl;
	cin >> NewStation.coefficient;

	cout << "������� ���������." << endl;
	StationNumber++;
}

void ViewingObjects(const Pipeline pipelines[], int PipeNumber,
	const CompressionStation stations[], int StationNumber) {
	cout << "���������� � ������:" << endl;
	for (int i = 0; i < PipeNumber; i++) {
		const Pipeline& pipe = pipelines[i];
		cout << "��� �����: " << pipe.name << endl;
		cout << "����� �����: " << pipe.length << endl;
		cout << "������� �����: " << pipe.diameter << endl;
		cout << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
		cout << "--------------------------" << endl;
	}
	cout << endl << endl << "���������� � ��������:" << endl;
	for (int i = 0; i < StationNumber; i++) {
		const CompressionStation& station = stations[i];
		cout << "��� �������: " << station.name << endl;
		cout << "���������� �����: " << station.WorkshopAmount << endl;
		cout << "���������� ������� �����: " << station.ProperAmount << endl;
		cout << "����������� �������������: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}


void EditPipeLine(Pipeline pipelines[], int& PipeNumber) {
	string name;
	string wish;
	bool pipeFound = false;

	cout << "������� �������� �����:" << endl;
	cin >> name;
	for (int i = 0; i < PipeNumber; i++) {
		if (pipelines[i].name == name) {
			if (pipelines[i].repairing == 1) {
				cout << "�� ������ ������ ����� � ������� ���������" << endl;
			}
			else {
				cout << "�� ������ ������ ����� �� � ������� ���������" << endl;
			}
			cout << "������� �������� �������� �����������������? Y/N" << endl;
			cin >> wish;
			if (wish == "Y") {
				pipelines[i].repairing = !pipelines[i].repairing;
				cout << "�������� ����������������� ��������" << endl;
			}
			else if (wish == "N") {
				cout << "�������� ����������������� �� ��������" << endl;
			}
			else {
				cout << "�� ����� �������� ��������. ��������� �����" << endl;
			}
			pipeFound = true;
			break;
		}
	}
	if (!pipeFound) {
		cout << "����� � ����� ��������� �� �������" << endl;
	}

}

void EditStation(CompressionStation stations[], int& StationNumber) {
	int NewProperAmount;
	string wish;
	bool StationFound = false;
	string name;
	cout << "������� �������� �������:" << endl;
	cin >> name;
	for (int i = 0; i < StationNumber; i++) {
		if (stations[i].name == name) {
			cout << "�� ������ ������ �������� ����� " << stations[i].ProperAmount << " �� " << stations[i].WorkshopAmount << endl;
			do {
				cout << "������� �������� ���������� ������� �����? Y/N" << endl;
				cin >> wish;
				if (wish == "Y") {
					cout << "������� ���������� ������� �����:" << endl;
					cin >> NewProperAmount;
					stations[i].ProperAmount = NewProperAmount;
				}
				else if (wish == "N") {
					cout << "���������� ������� ����� �������� �������" << endl;
				}
				else {
					cout << "�� ����� �������� ��������. ��������� �����" << endl;
				}
				StationFound = true;
				break;
			} while (wish != "Y" && wish != "N");
		}
	}
	if (!StationFound) {
		cout << "������� � ����� ��������� �� �������" << endl;
	}
}


void Save(const Pipeline pipelines[], int PipeNumber,
	const CompressionStation stations[], int StationNumber) {
	ofstream file("SavedData.txt");
	if (!file.is_open()) {
		cout << "�� ������� ������� ���� ��� ������." << endl;
		return;
	}
	file << "���������� � �������������:" << endl;
	for (int i = 0; i < PipeNumber; i++) {
		const Pipeline& pipe = pipelines[i];
		file << "��� �����: " << pipe.name << endl;
		file << "����� �����: " << pipe.length << endl;
		file << "������� �����: " << pipe.diameter << endl;
		file << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
		file << "--------------------------" << endl;
	}
	file.close();
	cout << "������ ���������" << endl;
}

void Download() {
	cout << "������ ���������" << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int Choice;
	Pipeline pipelines[MaxPipelines];
	CompressionStation stations[MaxStations];
	int PipeNumber = 0;
	int StationNumber = 0;


	for (;;) {
		cout << "������� 1, ����� �������� �����\n";
		cout << "������� 2, ����� �������� �������\n";
		cout << "������� 3, ����� ����������� ��� �������\n";
		cout << "������� 4, ����� ������������� �����\n";
		cout << "������� 5, ����� ������������� �������\n";
		cout << "������� 6, ����� ���������\n";
		cout << "������� 7, ����� ���������\n";
		cout << "������� 0, ����� �����\n";

		cin >> Choice;

		switch (Choice) {
		case 1: {
			AddPipeLine(pipelines, PipeNumber);
			break;
		}
		case 2: {
			AddStation(stations, StationNumber);
			break;
		}
		case 3: {
			ViewingObjects(pipelines, PipeNumber, stations, StationNumber);
			break;
		}
		case 4: {
			EditPipeLine(pipelines, PipeNumber);
			break;
		}
		case 5: {
			EditStation(stations, StationNumber);
			break;
		}
		case 6: {
			Save(pipelines, PipeNumber, stations, StationNumber);
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
	}
}
