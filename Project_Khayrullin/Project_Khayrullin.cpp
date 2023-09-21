#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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

void AddPipeLine(Pipeline pipelines[], int& PipeNumber,const int MaxPipelines)
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
	while (!(cin >> NewPipe.length) || NewPipe.length <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "�� ����� �������� ��������. ��������� �����" << endl;
	}
	cout << "������� ������� �����:" << endl;
	while (!(cin >> NewPipe.diameter) || NewPipe.diameter <= 0 || NewPipe.diameter >= NewPipe.length) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "�� ����� �������� ��������. ��������� �����" << endl;

	}
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
void AddStation(CompressionStation stations[], int& StationNumber,const int MaxStations) {
	if (StationNumber >= MaxStations) {
		cout << "���������� ������������ ���������� �������" << endl;
		return;
	}

	CompressionStation& NewStation = stations[StationNumber];

	cout << "������� �������� �������:" << endl;
	cin >> NewStation.name;
	cout << "������� ���������� �����:" << endl;
	while (!(cin >> NewStation.WorkshopAmount) || NewStation.WorkshopAmount <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "�� ����� �������� ��������. ��������� �����" << endl;

	}
	cout << "������� ���������� ������� �����:" << endl;
	while (!(cin >> NewStation.ProperAmount) || NewStation.ProperAmount > NewStation.WorkshopAmount || NewStation.ProperAmount <0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "�� ����� �������� ��������. ��������� �����" << endl;

	}
	cout << "������� ����������� ������������� 0-1:" << endl;
	while (!(cin >> NewStation.coefficient) || NewStation.coefficient < 0 || NewStation.coefficient >1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "�� ����� �������� ��������. ��������� �����" << endl;
	}

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
	
	for (int i = 0; i < PipeNumber; i++) {
		const Pipeline& pipe = pipelines[i];
		file << "�����������:" << endl;
		file << pipe.name << endl;
		file << pipe.length << endl;
		file << pipe.diameter << endl;
		file << (pipe.repairing ? "Y" : "N") << endl;
	}

	for (int i = 0; i < StationNumber; i++) {
		const CompressionStation& station = stations[i];
		file << "�������:" << endl;
		file << station.name << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "������ ��������� � ���� SavedData.txt" << endl;
}

void LoadData(Pipeline pipelines[], int& PipeNumber,
	CompressionStation stations[], int& StationNumber) {
	string line;
	PipeNumber = 0;
	StationNumber = 0;
	string isRepairing;
	ifstream file("SavedData.txt");
	if (!file.is_open()) {
		cout << "�� ������� ������� ���� ��� ������." << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "�����������:") {
			file >> pipelines[PipeNumber].name >> pipelines[PipeNumber].length >> pipelines[PipeNumber].diameter >> isRepairing;
			pipelines[PipeNumber].repairing = (isRepairing == "Y" ? true : false);
			++PipeNumber;
		}
		else if(line == "�������:") {
			file >> stations[StationNumber].name >> stations[StationNumber].WorkshopAmount >> stations[StationNumber].ProperAmount >>stations[StationNumber].coefficient;
			++StationNumber;
		}
	}

	file.close();
	cout << "������ ��������� �� ����� SavedData.txt." << endl;
}



int main() {
	setlocale(LC_ALL, "RUS");
	int Choice;
	const int MaxPipelines=100;
	const int MaxStations=100;
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

		while (!(cin >> Choice) || Choice >7 || Choice <0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "���������� ��� ���:" << endl;
		}

		switch (Choice) {
		case 1: {
			AddPipeLine(pipelines, PipeNumber, MaxPipelines);
			break;
		}
		case 2: {
			AddStation(stations, StationNumber, MaxStations);
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
			LoadData(pipelines, PipeNumber, stations, StationNumber);
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
	return 0;
}
