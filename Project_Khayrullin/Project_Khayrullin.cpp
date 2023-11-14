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
		cout << "������� 1, ����� �������� �����\n";
		cout << "������� 2, ����� �������� �������\n";
		cout << "������� 3, ����� ����������� �������\n";
		cout << "������� 4, ����� ������������� �����\n";
		cout << "������� 5, ����� ������������� �������\n";
		cout << "������� 6, ����� ���������\n";
		cout << "������� 7, ����� ���������\n";
		cout << "������� 0, ����� �����\n";

		switch (InputValue<int>(0, 7)) {
		case 1: {
			Pipeline pipe;
			pipe.AddPipeLine();
			pipelines.insert({ pipe.getid(), pipe });
			cout << "����� ���������." << endl;
			break;
		}
		case 2: {
			CompressionStation station;
			station.AddStation();
			stations.insert({ station.getid(), station });
			cout << "������� ���������." << endl;
			break;
		}
		case 3: {
			cout << "������� ����������� ��� ��������?" << endl;
			if (Confirm()) {
				Pipeline::ViewingPipes(pipelines);
				CompressionStation::ViewingStations(stations);
			}
			else {
				cout << "1.����������� �����"<< "\n" << "2.����������� ������������� �������" << endl;
				(InputValue<int>(1, 2) == 1) ? filterPipe(pipelines):filterStation(stations);
			}
			break;
		}
		case 4: {
			cout << "1.�������� �������� �����������������\n" << "2.������� �����" << endl;
			(InputValue<int>(1, 2) == 1) ? Pipeline::ChangePipe(pipelines) : Pipeline::DeletePipe(pipelines);
			break;
		}
		case 5: {
			cout << "1.�������� ���������� ������� �����\n" << "2.������� �������" << endl;
			(InputValue<int>(1, 2) == 1) ? CompressionStation::ChangeStation(stations) : CompressionStation::DeleteStation(stations);
			break;
		}
		case 6: {
			cout << "������� ��� ����� ��� ���������� ������: ";
			string fileName = InputString();
			Pipeline::SavePipes(pipelines, fileName);
			CompressionStation::SaveStations(stations,fileName);
			break;
		}
		case 7: {
			cout << "������� ��� ����� ��� �������� ������: ";
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
