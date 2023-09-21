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
		cout << "Достигнуто максимальное количество трубопроводов." << endl;
		return;
	}

	Pipeline& NewPipe = pipelines[PipeNumber];

	cout << "Введите имя трубы:" << endl;
	cin >> NewPipe.name;
	cout << "Введите длину трубы:" << endl;
	cin >> NewPipe.length;
	cout << "Введите диаметр трубы:" << endl;
	cin >> NewPipe.diameter;
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
void AddStation(CompressionStation stations[], int& StationNumber) {
	if (StationNumber >= MaxStations) {
		cout << "Достигнуто максимальное количество станций" << endl;
		return;
	}

	CompressionStation& NewStation = stations[StationNumber];

	cout << "Введите название станции:" << endl;
	cin >> NewStation.name;
	cout << "Введите количество цехов:" << endl;
	cin >> NewStation.WorkshopAmount;
	cout << "Введите количество рабочих цехов:" << endl;
	cin >> NewStation.ProperAmount;
	cout << "Введите коэффициент эффективности 0-1:" << endl;
	cin >> NewStation.coefficient;

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
	file << "Информация о трубопроводах:" << endl;
	for (int i = 0; i < PipeNumber; i++) {
		const Pipeline& pipe = pipelines[i];
		file << "Имя трубы: " << pipe.name << endl;
		file << "Длина трубы: " << pipe.length << endl;
		file << "Диаметр трубы: " << pipe.diameter << endl;
		file << "В рабочем состоянии: " << (pipe.repairing ? "Да" : "Нет") << endl;
		file << "--------------------------" << endl;
	}
	file.close();
	cout << "Данные сохранены" << endl;
}

void Download() {
	cout << "Данные загружены" << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int Choice;
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
