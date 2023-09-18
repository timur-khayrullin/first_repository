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
        cout << "���������� ������������ ���������� �������������." << endl;
        return;
    }

    Pipeline& NewPipe = pipelines[PipeNumber];

    cout << "������� ��� �����:" << endl;
    cin >> NewPipe.name;
    cout << "������� ����� �����:" << endl;
    cin >> NewPipe.length;
    cout << "������� ������� �����:" << endl;
    cin >> NewPipe.diameter;
    cout << "� ������� ���������? 1/0:" << endl;
    cin >> NewPipe.repairing;

    cout << "����� ���������." << endl;
    PipeNumber++;
}

void ViewingObjects(const Pipeline pipelines[], int PipeNumber) {
    cout << "���������� � �������������:" << endl;
    for (int i = 0; i < PipeNumber; i++) {
        const Pipeline& pipe = pipelines[i];
        cout << "��� �����: " << pipe.name << endl;
        cout << "����� �����: " << pipe.length << endl;
        cout << "������� �����: " << pipe.diameter << endl;
        cout << "� ������� ���������: " << (pipe.repairing ? "��" : "���") << endl;
        cout << "--------------------------" << endl;
    }
}

void AddStation() {
    cout << "������� ���������" << endl;
}

void EditPipeLine() {
    cout << "������ ����� ��������" << endl;
}

void EditStation() {
    cout << "������ ������� ��������" << endl;
}

void Save() {
    cout << "������ ���������" << endl;
}

void Download() {
    cout << "������ ���������" << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int Choice;
    Pipeline pipelines[MaxPipelines];
    int PipeNumber = 0;

    for (;;) {
        cout << "������� 1, ����� �������� �����\n";
        cout << "������� 2, ����� �������� �������\n";
        cout << "������� 3, ����� ����������� ��� �������\n";
        cout << "������� 4, ����� ������������� �����\n";
        cout << "������� 5, ����� ������������� �������\n";
        cout << "������� 6, ����� ���������\n";
        cout << "������� 7, ����� ���������\n";
        cout << "������� 0, ����� �����\n";

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
