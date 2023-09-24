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
	double coefficient;
};

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
double InputDouble(int min = 0, double max= 10000000) {
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


void AddPipeLine(Pipeline pipelines[], int& PipeNumber, const int& MaxPipelines)
{
	if (PipeNumber >= MaxPipelines) {
		cout << "���������� ������������ ���������� �������������." << endl;
		return;
	}
	Pipeline& NewPipe = pipelines[PipeNumber];
	cout << "������� ��� �����:" << endl;
	NewPipe.name = InputString();
	cout << "������� ����� �����:" << endl;
	NewPipe.length = InputDouble(0, 10000000);
	cout << "������� ������� �����:" << endl;
	NewPipe.diameter = InputDouble(0, NewPipe.length);
	cout << "� ������� ���������?" << endl;
	NewPipe.repairing = Confirm();
	cout << "����� ���������." << endl;
	PipeNumber++;
}
void AddStation(CompressionStation stations[], int& StationNumber,const int& MaxStations) {
	if (StationNumber >= MaxStations) {
		cout << "���������� ������������ ���������� �������" << endl;
		return;
	}
	CompressionStation& NewStation = stations[StationNumber];
	cout << "������� �������� �������:" << endl;
	NewStation.name = InputString();
	cout << "������� ���������� �����:" << endl;
	NewStation.WorkshopAmount = InputInt(0, 1000);
	cout << "������� ���������� ������� �����:" << endl;
	NewStation.ProperAmount = InputInt(0, NewStation.WorkshopAmount);
	cout << "������� ����������� ������������� 0-1:" << endl;
	NewStation.coefficient = InputDouble(0, 1);
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

void EditPipeLine(Pipeline& Pipe) {
	cout << "������� �������� �������� �����������������?" << endl;
	if (Confirm()) {
		Pipe.repairing = !Pipe.repairing;
	}
}

void ChoosePipe(Pipeline pipelines[],int& PipeNumber) {
	bool PipeFound = false;
	string name;
	int ChosenPipe;
	cout << "������� ��� �����:" << endl;
	name= InputString();
	for (int i = 0; i < PipeNumber; i++) {
		if (pipelines[i].name == name) {
			cout << (pipelines[i].repairing == 1 ? "� ������ ������ ����� ��������" : "� ������ ������ ����� �� ��������") << endl;
			ChosenPipe = i;
			PipeFound = true;
			EditPipeLine(pipelines[ChosenPipe]);
			break;
		}
	}
	if (!PipeFound) {
		cout << "����� � ����� ��������� �� �������" << endl;
	}


}

void EditStation(CompressionStation& station) {
	cout << "������� �������� ���������� ������� �����?" << endl;
	if (Confirm())
	{
		cout << "������� ���������� ������� �����:" << endl;
		station.ProperAmount = InputInt(0, station.WorkshopAmount);
	}
}

void ChooseStation(CompressionStation stations[], int& StationNumber) {
	bool StationFound = false;
	string name;
	int ChosenStation;
	cout << "������� �������� �������:" << endl;
	name = InputString();
	for (int i = 0; i < StationNumber; i++) {
		if (stations[i].name == name) {
			cout << "�� ������ ������ �������� ����� " << stations[i].ProperAmount << " �� " << stations[i].WorkshopAmount << endl;
			ChosenStation = i;
			StationFound = true;
			EditStation(stations[ChosenStation]);
			break;
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

		switch (InputInt(0, 7)) {
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
			ChoosePipe(pipelines, PipeNumber);
			break;
		}
		case 5: {
			ChooseStation(stations, StationNumber);
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
