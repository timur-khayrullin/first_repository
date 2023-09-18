#include <iostream>

using namespace std;

const int MaxPipelines = 50;

struct Pipeline {
    string name;
    double length;
    double diameter;
    bool repairing;
};
struct KStation {
    string name;
    int WorkshopAmount;
    int ProperAmount;
    float cofficient;
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

void ViewingObjects(const Pipeline pipelines[], int PipeNumber) {
    cout << "Информация о трубопроводах:" << endl;
    for (int i = 0; i < PipeNumber; i++) {
        const Pipeline& pipe = pipelines[i];
        cout << "Имя трубы: " << pipe.name << endl;
        cout << "Длина трубы: " << pipe.length << endl;
        cout << "Диаметр трубы: " << pipe.diameter << endl;
        cout << "В рабочем состоянии: " << (pipe.repairing ? "Да" : "Нет") << endl;
        cout << "--------------------------" << endl;
    }
}

void AddStation() {
    cout << "Станция добавлена" << endl;
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
    int PipeNumber = 0;

    for (;;) {
        cout << "Нажмите 1, чтобы добавить трубу\n";
        cout << "Нажмите 2, чтобы добавить станцию\n";
        cout << "Нажмите 3, чтобы просмотреть все объекты\n";
        cout << "Нажмите 4, чтобы редактировать трубу\n";
        cout << "Нажмите 5, чтобы редактировать станцию\n";
        cout << "Нажмите 6, чтобы сохранить\n";
        cout << "Нажмите 7, чтобы загрузить\n";
        cout << "Нажмите 0, чтобы ВЫЙТИ\n";

        cin >> Choice;

        switch (Choice) {
        case 1: {
            AddPipeLine(pipelines, PipeNumber);
            break;
        }
        case 2: {
            AddStation();
            break;
        }
        case 3: {
            ViewingObjects(pipelines, PipeNumber);
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
