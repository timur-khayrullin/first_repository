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
			cout << "������� ��� ����� ��� ���������� ������: ";
			cin >> fileName;
			Pipeline pipe;
			pipe.SavePipes(pipelines, fileName);
			CompressionStation station;
			station.SaveStations(stations,fileName);
			break;
		}
		case 7: {
			string fileName;
			cout << "������� ��� ����� ��� �������� ������: ";
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
