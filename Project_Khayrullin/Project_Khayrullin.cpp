#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipeline.h"
#include "CompressionStation.h"
#include "utils.h"



using namespace std;



int main() {
	setlocale(LC_ALL, "RUS");
	Pipeline m;
	unordered_map<string, Pipeline> pipelines;
	unordered_map<string, CompressionStation> stations;

	for (;;) {
		cout << "¬ведите 1, чтобы добавить трубу\n";
		cout << "¬ведите 2, чтобы добавить станцию\n";
		cout << "¬ведите 3, чтобы просмотреть все объекты\n";
		cout << "¬ведите 4, чтобы редактировать трубу\n";
		cout << "¬ведите 5, чтобы редактировать станцию\n";
		cout << "¬ведите 6, чтобы сохранить\n";
		cout << "¬ведите 7, чтобы загрузить\n";
		cout << "¬ведите 0, чтобы ¬џ…“»\n";

		switch (InputInt(0, 7)) {
		case 1: {
			Pipeline pipe;
			pipe.AddPipeLine(pipelines);
			break;
		}
		case 2: {
			CompressionStation station;
			station.AddStation(stations);
			break;
		}
		case 3: {
			Pipeline pipe;
			pipe.ViewingPipes(pipelines);
			CompressionStation station;
			station.ViewingStations(stations);
			break;
		}
		case 4: {
			Pipeline pipe;
			pipe.ChoosePipe(pipelines);
			break;
		}
		case 5: {
			CompressionStation station;
			station.ChooseStation(stations);
			break;
		}
		case 6: {
			string fileName;
			cout << "¬ведите им€ файла дл€ сохранени€ данных: ";
			cin >> fileName;
			Pipeline pipe;
			pipe.SavePipes(pipelines, fileName);
			CompressionStation station;
			station.SaveStations(stations,fileName);
			break;
		}
		case 7: {
			string fileName;
			cout << "¬ведите им€ файла дл€ загрузки данных: ";
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
