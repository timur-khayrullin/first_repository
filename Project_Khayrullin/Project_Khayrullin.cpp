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
		cout << "Достигнуто максимальное количество трубопроводов." << endl;
		return;
	}

	Pipeline& NewPipe = pipelines[PipeNumber];

	cout << "Введите имя трубы:" << endl;
	cin >> NewPipe.name;
	cout << "Введите длину трубы:" << endl;
	while (!(cin >> NewPipe.length) || NewPipe.length <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели неверное значение. Повторите снова" << endl;
	}
	cout << "Введите диаметр трубы:" << endl;
	while (!(cin >> NewPipe.diameter) || NewPipe.diameter <= 0 || NewPipe.diameter >= NewPipe.length) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели неверное значение. Повторите снова" << endl;

	}
	do {
		cout << "В рабочем состоянии? Y/N:" << endl;
		cin >> isRepairing;
		if (isRepairing == "Y") {
			NewPipe.repairing = 1;
		}
		else if (isRepairing == "N") {
			NewPipe.repairing = 0;
		}
		else {
			cout << "Вы ввели неверное значение. Повторите снова" << endl;
		}
	} while (isRepairing != "Y" && isRepairing != "N");
	cout << "Труба добавлена." << endl;
	PipeNumber++;
}
void AddStation(CompressionStation stations[], int& StationNumber,const int MaxStations) {
	if (StationNumber >= MaxStations) {
		cout << "Достигнуто максимальное количество станций" << endl;
		return;
	}

	CompressionStation& NewStation = stations[StationNumber];

	cout << "Введите название станции:" << endl;
	cin >> NewStation.name;
	cout << "Введите количество цехов:" << endl;
	while (!(cin >> NewStation.WorkshopAmount) || NewStation.WorkshopAmount <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели неверное значение. Повторите снова" << endl;

	}
	cout << "Введите количество рабочих цехов:" << endl;
	while (!(cin >> NewStation.ProperAmount) || NewStation.ProperAmount > NewStation.WorkshopAmount || NewStation.ProperAmount <0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели неверное значение. Повторите снова" << endl;

	}
	cout << "Введите коэффициент эффективности 0-1:" << endl;
	while (!(cin >> NewStation.coefficient) || NewStation.coefficient < 0 || NewStation.coefficient >1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели неверное значение. Повторите снова" << endl;
	}

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


void EditPipeLine(Pipeline pipelines[], int& PipeNumber) {
	string name;
	string wish;
	bool pipeFound = false;

	cout << "Введите названия трубы:" << endl;
	cin >> name;
	for (int i = 0; i < PipeNumber; i++) {
		if (pipelines[i].name == name) {
			if (pipelines[i].repairing == 1) {
				cout << "На данный момент труба в рабочем состоянии" << endl;
			}
			else {
				cout << "На данный момент труба НЕ в рабочем состоянии" << endl;
			}
			cout << "Желаете изменить значение работоспособности? Y/N" << endl;
			cin >> wish;
			if (wish == "Y") {
				pipelines[i].repairing = !pipelines[i].repairing;
				cout << "Значение работоспособности изменено" << endl;
			}
			else if (wish == "N") {
				cout << "Значение работоспособности не изменено" << endl;
			}
			else {
				cout << "Вы ввели неверное значение. Повторите снова" << endl;
			}
			pipeFound = true;
			break;
		}
	}
	if (!pipeFound) {
		cout << "Трубы с таким названием не найдено" << endl;
	}

}

void EditStation(CompressionStation stations[], int& StationNumber) {
	int NewProperAmount;
	string wish;
	bool StationFound = false;
	string name;
	cout << "Введите название станции:" << endl;
	cin >> name;
	for (int i = 0; i < StationNumber; i++) {
		if (stations[i].name == name) {
			cout << "На данный момент работает цехов " << stations[i].ProperAmount << " из " << stations[i].WorkshopAmount << endl;
			do {
				cout << "Желаете изменить количество рабочих цехов? Y/N" << endl;
				cin >> wish;
				if (wish == "Y") {
					cout << "Введите количество рабочих цехов:" << endl;
					cin >> NewProperAmount;
					stations[i].ProperAmount = NewProperAmount;
				}
				else if (wish == "N") {
					cout << "Количество рабочих цехов осталось прежним" << endl;
				}
				else {
					cout << "Вы ввели неверное значение. Повторите снова" << endl;
				}
				StationFound = true;
				break;
			} while (wish != "Y" && wish != "N");
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
		return;
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
	int Choice;
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

		while (!(cin >> Choice) || Choice >7 || Choice <0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Попробуйте ещё раз:" << endl;
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
