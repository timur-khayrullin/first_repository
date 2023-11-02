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


void AddPipeLine(unordered_map<string, Pipeline>& pipelines)
{
	string name;

	cout << "Введите имя трубы:" << endl;
	name = InputString();
	if (pipelines.find(name) != pipelines.end()) {
		cout << "Труба с таким именем уже существует" << endl;
		return;
	}
	Pipeline NewPipe;
	cout << "Введите длину трубы:" << endl;
	NewPipe.length = InputDouble(0, 10000000);
	cout << "Введите диаметр трубы:" << endl;
	NewPipe.diameter = InputDouble(0, NewPipe.length);
	cout << "В рабочем состоянии?" << endl;
	NewPipe.repairing = Confirm();
	pipelines[name] = NewPipe;
	cout << "Труба добавлена." << endl;
}
void AddStation(unordered_map<string, CompressionStation>& stations) {
	string name;

	cout << "Введите название станции:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
		cout << "Труба с таким именем уже существует" << endl;
		return;
	}
	CompressionStation NewStation;
	cout << "Введите количество цехов:" << endl;
	NewStation.WorkshopAmount = InputInt(0, 1000);
	cout << "Введите количество рабочих цехов:" << endl;
	NewStation.ProperAmount = InputInt(0, NewStation.WorkshopAmount);
	cout << "Введите коэффициент эффективности 0-1:" << endl;
	NewStation.coefficient = InputDouble(0, 1);
	stations[name] = NewStation;
	cout << "Станция добавлена." << endl;

}
void ViewingObjects(const unordered_map<string, Pipeline>& pipelines,
	const unordered_map<string, CompressionStation> stations) {
	cout << "ИНФОРМАЦИЯ О ТРУБАХ:" << endl;
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		cout << "Имя трубы: " << pair.first << endl;
		cout << "Длина трубы: " << pipe.length << endl;
		cout << "Диаметр трубы: " << pipe.diameter << endl;
		cout << "В рабочем состоянии: " << (pipe.repairing ? "Да" : "Нет") << endl;
		cout << "--------------------------" << endl;
	}
	cout << endl << endl << "ИНФОРМАЦИЯ О СТАНЦИЯХ:" << endl;
	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		cout << "Имя станции: " << pair.first << endl;
		cout << "Количество цехов: " << station.WorkshopAmount << endl;
		cout << "Количество рабочих цехов: " << station.ProperAmount << endl;
		cout << "Коэффициент эффективности: " << station.coefficient << endl;
		cout << "--------------------------" << endl;
	}
}

void EditPipeLine(unordered_map<string, Pipeline>& pipelines, const string& pipeName) {
	cout << "Желаете изменить значение работоспособности?" << endl;
	if (Confirm()) {
		pipelines[pipeName].repairing = !pipelines[pipeName].repairing;
		cout << "Значение работоспособности трубы изменено" << endl;
	}
}

void ChoosePipe(unordered_map<string, Pipeline>& pipelines) {
	string name;
	cout << "Введите имя трубы:" << endl;
	name = InputString();
	if (pipelines.find(name) != pipelines.end()) {
		cout << (pipelines[name].repairing ? "В данный момент труба работает" : "В данный момент труба НЕ работает") << endl;
		EditPipeLine(pipelines, name);
	}
	else {
		cout << "Трубы с таким именем не найдено" << endl;
	}
}

void EditStation(unordered_map<string, CompressionStation>& stations, const string& stationName) {
	cout << "Желаете изменить количество рабочих цехов?" << endl;
	if (Confirm()) {
		cout << "Введите количество рабочих цехов:" << endl;
		stations[stationName].ProperAmount = InputInt(0, stations[stationName].WorkshopAmount);
	}
}

void ChooseStation(unordered_map<string, CompressionStation>& stations) {
	string name;
	cout << "Введите название станции:" << endl;
	name = InputString();
	if (stations.find(name) != stations.end()) {
			cout << "На данный момент работает цехов " << stations[name].ProperAmount << " из " << stations[name].WorkshopAmount << endl;
			EditStation(stations, name);
		}
	else {
		cout << "Станции с таким именем не найдено" << endl;
	}
}

void Save(const unordered_map<string, Pipeline>& pipelines,
	const unordered_map<string, CompressionStation>& stations) {
	string fileName;
	cout << "Введите имя файла для сохранения данных: ";
	cin >> fileName;
	ofstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	for (const auto& pair : pipelines) {
		const Pipeline& pipe = pair.second;
		file << "Трубопровод:" << endl;
		file << pair.first << endl;
		file << pipe.length << endl;
		file << pipe.diameter << endl;
		file << (pipe.repairing ? "Y" : "N") << endl;
	}

	for (const auto& pair : stations) {
		const CompressionStation& station = pair.second;
		file << "Станция:" << endl;
		file << pair.first << endl;
		file << station.WorkshopAmount << endl;
		file << station.ProperAmount << endl;
		file << station.coefficient << endl;
	}
	file.close();
	cout << "Данные сохранены в файл: " << fileName << endl;
}

void LoadData(unordered_map<string, Pipeline>& pipelines, unordered_map<string, CompressionStation>& stations) {
	string fileName;
	string line;
	string name;
	string isRepairing;
	cout << "Введите имя файла для загрузки данных: ";
	cin >> fileName;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	while (getline(file, line)) {
		if (line == "Трубопровод:") {
			Pipeline pipe;
			getline(file, name);
			file >> pipe.length >> pipe.diameter >> isRepairing;
			pipe.repairing = (isRepairing == "Y" ? true : false);
			pipelines[name] = pipe;
		}
		else if(line == "Станция:") {
			CompressionStation station;
			getline(file, name);
			file >> station.WorkshopAmount >> station.ProperAmount >>station.coefficient;
			stations[name] = station;
		}
	}

	file.close();
	cout << "Данные загружены из файла: " << fileName << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");
	unordered_map<string, Pipeline> pipelines;
	unordered_map<string, CompressionStation> stations;

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
