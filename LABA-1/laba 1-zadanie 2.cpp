#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int k,nehet;
	int b,a;
	float n = 0;
	cout << "Введите число с которого будет начинаться массив:";
	cin >> a;
	cout << "Введите число на котором будет заканчиваться массив:";
	cin >> b;
	float *massiv = new float[20];
	while (n < 20) {
		massiv[n] = a + (rand() % (b - a + 1));
		n++;
	}
	cout << "Введите число k:";
	cin >> k;
	n = 0;
	while (n < 20) {
		if (massiv[n] % 2 != 0) {
			nehet += 1;
		}
	}
	n = 0;
	while (n < 20) {
		cout << massiv[n] << " ";
		n++;
	}
	cout << endl;
	system("pause");
}
