#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "utils.h"
using namespace std;

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
double InputDouble(int min = 0, double max = 10000000) {
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