#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

struct Pipeline {
	double length;
	double diameter;
	bool repairing;
};
struct CompressionStation {
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


void AddPipeLine(unordered_map<string, Pipeline>& pipelines)
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
void AddStation(unordered_map<string, CompressionStation>& stations) {
	string name;

	cout << "������� �������� �������:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
		cout << "����� � ����� ������ ��� ����������" << endl;
		return;
	}
	CompressionStation NewStation;
	cout << "������� ���������� �����:" << endl;
	NewStation.WorkshopAmount = InputInt(0, 1000);
	cout << "������� ���������� ������� �����:" << endl;
	NewStation.ProperAmount = InputInt(0, NewStation.WorkshopAmount);
	cout << "������� ����������� ������������� 0-1:" << endl;
	NewStation.coefficient = InputDouble(0, 1);
	stations[name] = NewStation;
	cout << "������� ���������." << endl;

}
void ViewingObjects(const unordered_map<string, Pipeline>& pipelines,
	const unordered_map<string, CompressionStation> stations) {
	cout << "���������� � ������:" << endl;
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		cout << "��� �����: " << pair.first << endl;
		cout << "����� �����: " << pipe.length << endl;
		cout << "������� �����: " << pipe.diameter << endl;
		cout << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
		cout << "--------------------------" << endl;
	}
	cout << endl << endl << "���������� � ��������:" << endl;
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		cout << "��� �������: " << pair.first << endl;
		cout << "���������� �����: " << station.WorkshopAmount << endl;
		cout << "���������� ������� �����: " << station.ProperAmount << endl;
		cout << "����������� �������������: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}

void EditPipeLine(unordered_map<string, Pipeline>& pipelines, const string& pipeName) {
	cout << "������� �������� �������� �����������������?" << endl;
	if (Confirm()) {
		pipelines[pipeName].repairing = !pipelines[pipeName].repairing;
		cout << "�������� ����������������� ����� ��������" << endl;
	}
}

void ChoosePipe(unordered_map<string, Pipeline>& pipelines) {
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

void EditStation(unordered_map<string, CompressionStation>& stations, const string& stationName) {
	cout << "������� �������� ���������� ������� �����?" << endl;
	if (Confirm()) {
		cout << "������� ���������� ������� �����:" << endl;
		stations[stationName].ProperAmount = InputInt(0, stations[stationName].WorkshopAmount);
	}
}

void ChooseStation(unordered_map<string, CompressionStation>& stations) {
	string name;
	cout << "������� �������� �������:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
			cout << "�� ������ ������ �������� ����� " << stations[name].ProperAmount << " �� " << stations[name].WorkshopAmount << endl;
			EditStation(stations, name);
		}
	else {
		cout << "������� � ����� ������ �� �������" << endl;
	}
}

void Save(const unordered_map<string, Pipeline>& pipelines,
	const unordered_map<string, CompressionStation>& stations) {
	string fileName;
	cout << "������� ��� ����� ��� ���������� ������: ";
	cin >> fileName;
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

	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		file << "�������:" << endl;
		file << pair.first << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "������ ��������� � ����: " << fileName << endl;
}

void LoadData(unordered_map<string, Pipeline>& pipelines, unordered_map<string, CompressionStation>& stations) {
	string fileName;
	string line;
	string name;
	string isRepairing;
	cout << "������� ��� ����� ��� �������� ������: ";
	cin >> fileName;
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
		else if(line == "�������:") {
			CompressionStation station;
			getline(file, name);
			file >> station.WorkshopAmount >> station.ProperAmount >>station.coefficient;
			stations[name] = station;
		}
	}

	file.close();
	cout << "������ ��������� �� �����: " << fileName << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");
	unordered_map<string, Pipeline> pipelines;
	unordered_map<string, CompressionStation> stations;

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
			AddPipeLine(pipelines);
			break;
		}
		case 2: {
			AddStation(stations);
			break;
		}
		case 3: {
			ViewingObjects(pipelines, stations);
			break;
		}
		case 4: {
			ChoosePipe(pipelines);
			break;
		}
		case 5: {
			ChooseStation(stations);
			break;
		}
		case 6: {
			Save(pipelines, stations);
			break;
		}
		case 7: {
			LoadData(pipelines, stations);
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
