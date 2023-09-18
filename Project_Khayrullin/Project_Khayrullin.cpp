#include <iostream>
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
	cout << "� ������� ���������? 1/0:" << endl;
	cin >> NewPipe.repairing;

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


void EditPipeLine() {
	cout << "������ ����� ��������" << endl;
}

void EditStation() {
	cout << "������ ������� ��������" << endl;
}

void Save() {
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
	}
}
