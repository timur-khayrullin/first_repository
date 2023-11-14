#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipeline.h"
#include "CompressionStation.h"
#include "utils.h"
#include <chrono>
#include <format>

using namespace std;
using namespace chrono;

int main() {
	setlocale(LC_ALL, "RUS");
	redirect_output_wrapper cerr_out(cerr);
	ofstream logfile("logging.txt");
	if (logfile)
		cerr_out.redirect(logfile);
	unordered_map<int, Pipeline> pipelines;
	unordered_map<int, CompressionStation> stations;

	for (;;) {
		cout << "Введите 1, чтобы добавить трубу\n";
		cout << "Введите 2, чтобы добавить станцию\n";
		cout << "Введите 3, чтобы просмотреть объекты\n";
		cout << "Введите 4, чтобы редактировать трубы\n";
		cout << "Введите 5, чтобы редактировать станции\n";
		cout << "Введите 6, чтобы сохранить\n";
		cout << "Введите 7, чтобы загрузить\n";
		cout << "Введите 0, чтобы ВЫЙТИ\n";

		switch (InputValue<int>(0, 7)) {
		case 1: {
			Pipeline pipe;
			pipe.AddPipeLine();
			pipelines.insert({ pipe.getid(), pipe });
			cout << "Труба добавлена." << endl;
			break;
		}
		case 2: {
			CompressionStation station;
			station.AddStation();
			stations.insert({ station.getid(), station });
			cout << "Станция добавлена." << endl;
			break;
		}
		case 3: {
			cout << "Желаете просмотреть все элементы?" << endl;
			if (Confirm()) {
				Pipeline::ViewingPipes(pipelines);
				CompressionStation::ViewingStations(stations);
			}
			else {
				cout << "1.Фильтровать трубы"<< "\n" << "2.Фильтровать компрессорные станции" << endl;
				(InputValue<int>(1, 2) == 1) ? filterPipe(pipelines):filterStation(stations);
			}
			break;
		}
		case 4: {
			cout << "1.Изменить значения работоспособности\n" << "2.Удалить трубы" << endl;
			(InputValue<int>(1, 2) == 1) ? Pipeline::ChangePipe(pipelines) : Pipeline::DeletePipe(pipelines);
			break;
		}
		case 5: {
			cout << "1.Изменить количество рабочих цехов\n" << "2.Удалить станции" << endl;
			(InputValue<int>(1, 2) == 1) ? CompressionStation::ChangeStation(stations) : CompressionStation::DeleteStation(stations);
			break;
		}
		case 6: {
			cout << "Введите имя файла для сохранения данных: ";
			string fileName = InputString();
			Pipeline::SavePipes(pipelines, fileName);
			CompressionStation::SaveStations(stations,fileName);
			break;
		}
		case 7: {
			cout << "Введите имя файла для загрузки данных: ";
			string fileName = InputString();
			Pipeline pipe;
			pipe.LoadPipes(pipelines, fileName);
			CompressionStation station;
			station.LoadStations(stations, fileName);
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
