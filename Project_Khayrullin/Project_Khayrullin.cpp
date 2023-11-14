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
	Pipeline m;
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
					if (InputValue<int>(1, 2) == 1) {
						filterPipe(pipelines);
					} else {
						filterStation(stations);
					}	
			}
			break;
		}
		case 4: {
			Pipeline::ChangePipe(pipelines);
			break;
		}
		case 5: {
			CompressionStation::ChangeStation(stations);
			break;
		}
		case 6: {
			string fileName;
			cout << "Введите имя файла для сохранения данных: ";
			cin >> fileName;
			Pipeline::SavePipes(pipelines, fileName);
			CompressionStation::SaveStations(stations,fileName);
			break;
		}
		case 7: {
			string fileName;
			cout << "Введите имя файла для загрузки данных: ";
			cin >> fileName;
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
