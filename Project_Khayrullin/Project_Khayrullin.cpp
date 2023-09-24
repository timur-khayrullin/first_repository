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
		cout << "Вы ввели неверное значение. Повторите снова" << endl;
	} 
}
int InputInt(int min = 0, int max = 1000)
{
	int x;
	while (!(cin >> x) || x > max || x < min) {
		cout << "Неверное значение. Попробуйте еще раз:" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return x;
}
double InputDouble(int min = 0, double max= 10000000) {
	double x;
	while (!(cin >> x) || x > max || x < min) {
		cout << "Неверное значение. Попробуйте еще раз:" << endl;
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
		cout << "Достигнуто максимальное количество трубопроводов." << endl;
		return;
	}
	Pipeline& NewPipe = pipelines[PipeNumber];
	cout << "Введите имя трубы:" << endl;
	NewPipe.name = InputString();
	cout << "Введите длину трубы:" << endl;
	NewPipe.length = InputDouble(0, 10000000);
	cout << "Введите диаметр трубы:" << endl;
	NewPipe.diameter = InputDouble(0, NewPipe.length);
	cout << "В рабочем состоянии?" << endl;
	NewPipe.repairing = Confirm();
	cout << "Труба добавлена." << endl;
	PipeNumber++;
}
void AddStation(CompressionStation stations[], int& StationNumber,const int& MaxStations) {
	if (StationNumber >= MaxStations) {
		cout << "Достигнуто максимальное количество станций" << endl;
		return;
	}
	CompressionStation& NewStation = stations[StationNumber];
	cout << "Введите название станции:" << endl;
	NewStation.name = InputString();
	cout << "Введите количество цехов:" << endl;
	NewStation.WorkshopAmount = InputInt(0, 1000);
	cout << "Введите количество рабочих цехов:" << endl;
	NewStation.ProperAmount = InputInt(0, NewStation.WorkshopAmount);
	cout << "Введите коэффициент эффективности 0-1:" << endl;
	NewStation.coefficient = InputDouble(0, 1);
	cout << "Станция добавлена." << endl;
	StationNumber++;
}
void ViewingObjects(const Pipeline pipelines[], int PipeNumber,
	const CompressionStation stations[], int StationNumber) {
	cout << "ИНФОРМАЦИЯ О ТРУБАХ:" << endl;
	for (int i = 0; i < PipeNumber; i++) {
		const Pipeline& pipe = pipelines[i];
		cout << "Имя трубы: " << pipe.name << endl;
		cout << "Длина трубы: " << pipe.length << endl;
		cout << "Диаметр трубы: " << pipe.diameter << endl;
		cout << "В рабочем состоянии: " << (pipe.repairing ? "Да" : "Нет") << endl;
		cout << "--------------------------" << endl;
	}
	cout << endl << endl << "ИНФОРМАЦИЯ О СТАНЦИЯХ:" << endl;
	for (int i = 0; i < StationNumber; i++) {
		const CompressionStation& station = stations[i];
		cout << "Имя станции: " << station.name << endl;
		cout << "Количество цехов: " << station.WorkshopAmount << endl;
		cout << "Количество рабочих цехов: " << station.ProperAmount << endl;
		cout << "Коэффициент эффективности: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}

void EditPipeLine(Pipeline& Pipe) {
	cout << "Желаете изменить значение работоспособности?" << endl;
	if (Confirm()) {
		Pipe.repairing = !Pipe.repairing;
	}
}

void ChoosePipe(Pipeline pipelines[],int& PipeNumber) {
	bool PipeFound = false;
	string name;
	int ChosenPipe;
	cout << "Введите имя трубы:" << endl;
	name= InputString();
	for (int i = 0; i < PipeNumber; i++) {
		if (pipelines[i].name == name) {
			cout << (pipelines[i].repairing == 1 ? "В данный момент труба работает" : "В данный момент труба НЕ работает") << endl;
			ChosenPipe = i;
			PipeFound = true;
			EditPipeLine(pipelines[ChosenPipe]);
			break;
		}
	}
	if (!PipeFound) {
		cout << "Трубы с таким названием не найдено" << endl;
	}


}

void EditStation(CompressionStation& station) {
	cout << "Желаете изменить количество рабочих цехов?" << endl;
	if (Confirm())
	{
		cout << "Введите количество рабочих цехов:" << endl;
		station.ProperAmount = InputInt(0, station.WorkshopAmount);
	}
}

void ChooseStation(CompressionStation stations[], int& StationNumber) {
	bool StationFound = false;
	string name;
	int ChosenStation;
	cout << "Введите название станции:" << endl;
	name = InputString();
	for (int i = 0; i < StationNumber; i++) {
		if (stations[i].name == name) {
			cout << "На данный момент работает цехов " << stations[i].ProperAmount << " из " << stations[i].WorkshopAmount << endl;
			ChosenStation = i;
			StationFound = true;
			EditStation(stations[ChosenStation]);
			break;
		}
	}
	if (!StationFound) {
		cout << "Станции с таким названием не найдено" << endl;
	}
}

void Save(const Pipeline pipelines[], int PipeNumber,
	const CompressionStation stations[], int StationNumber) {
	ofstream file("SavedData.txt");
	if (!file.is_open()) {
		cout << "Не удалось открыть файл для записи." << endl;
	}
	
	for (int i = 0; i < PipeNumber; i++) {
		const Pipeline& pipe = pipelines[i];
		file << "Трубопровод:" << endl;
		file << pipe.name << endl;
		file << pipe.length << endl;
		file << pipe.diameter << endl;
		file << (pipe.repairing ? "Y" : "N") << endl;
	}

	for (int i = 0; i < StationNumber; i++) {
		const CompressionStation& station = stations[i];
		file << "Станция:" << endl;
		file << station.name << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "Данные сохранены в файл SavedData.txt" << endl;
}

void LoadData(Pipeline pipelines[], int& PipeNumber,
	CompressionStation stations[], int& StationNumber) {
	string line;
	PipeNumber = 0;
	StationNumber = 0;
	string isRepairing;
	ifstream file("SavedData.txt");
	if (!file.is_open()) {
		cout << "Не удалось открыть файл для чтения." << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "Трубопровод:") {
			file >> pipelines[PipeNumber].name >> pipelines[PipeNumber].length >> pipelines[PipeNumber].diameter >> isRepairing;
			pipelines[PipeNumber].repairing = (isRepairing == "Y" ? true : false);
			++PipeNumber;
		}
		else if(line == "Станция:") {
			file >> stations[StationNumber].name >> stations[StationNumber].WorkshopAmount >> stations[StationNumber].ProperAmount >>stations[StationNumber].coefficient;
			++StationNumber;
		}
	}

	file.close();
	cout << "Данные загружены из файла SavedData.txt." << endl;
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
		cout << "Введите 1, чтобы добавить трубу\n";
		cout << "Введите 2, чтобы добавить станцию\n";
		cout << "Введите 3, чтобы просмотреть все объекты\n";
		cout << "Введите 4, чтобы редактировать трубу\n";
		cout << "Введите 5, чтобы редактировать станцию\n";
		cout << "Введите 6, чтобы сохранить\n";
		cout << "Введите 7, чтобы загрузить\n";
		cout << "Введите 0, чтобы ВЫЙТИ\n";

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
