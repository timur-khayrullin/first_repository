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
	cout << "В рабочем состоянии? 1/0:" << endl;
	cin >> NewPipe.repairing;

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


void EditPipeLine() {
	cout << "Данные трубы изменены" << endl;
}

void EditStation() {
	cout << "Данные станции изменены" << endl;
}

void Save() {
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
