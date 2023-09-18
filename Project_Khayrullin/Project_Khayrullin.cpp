#include <iostream>
#include <cstdio>
using namespace std;

struct Pipeline {
	string name;
	double length;
	double diameter;
	bool repairing;
};
void AddPipeLine(Pipeline& NewPipe) {
	cout << "Введите имя турбы:" << endl;
	cin >> NewPipe.name;
	cout << "Введите длину турбы:" << endl;
	cin >> NewPipe.length;
	cout << "Введите диаметр турбы:" << endl;
	cin >> NewPipe.diameter;
	cout << "В рабочем сосоянии? 1/0:" << endl;
	cin >> NewPipe.repairing;
	cout << "Труба добавлена." << endl;
}
void AddStation() {
	cout << "station added" << endl;
}
void ViewingObjects(string naming) {
	cout << naming;
}
void EditPipeLine(){

}
void EditStation() {

}
void Save() {

}
void Download() {

}
int main()
{
	setlocale(LC_ALL, "RUS");
	int Choice;



	for (;;) {
		cout << "Нажмите 1, чтобы добавить трубу\n";
		cout << "Нажмите 2, чтобы добавить добавить КС\n";
		cout << "Нажмите 3, чтобы просмотреть все объекты\n";
		cout << "Нажмите 4, чтобы редактировать трубу\n";
		cout << "Нажмите 5, чтобы редактировать КС\n";
		cout << "Нажмите 6, чтобы сохранить\n";
		cout << "Нажмите 7, чтобы загрузить\n";
		cout << "Нажмите 0, чтобы ВЫЙТИ\n";

		cin >> Choice;

		switch (Choice) {
		case 1: {
			Pipeline Pipe1;
			AddPipeLine(Pipe1);
			break;
		}
		case 2: {
			AddStation();
			break;
		}
		case 3: {
			ViewingObjects(Pipe1);
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
	};
}
