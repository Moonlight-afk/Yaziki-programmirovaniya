#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int chet = 0, n, i = 0, k = 0;
	cout << "Введите размер массива:";
	cin >> n;
	if (n < 5) {
		while (n < 5) {
			cout << "Некорректный ввод" << endl;
			cout << "Введите размер массива:";
			cin >> n;
		}
	}
	int* a = new int[n];
	//открываем файл
	ifstream file("C:\\Users\\стас\\source\\repos\\Project2\\massiv.txt");
	if (!file) {
		cout << "Ошибка" << endl;
	}
	else {
		//заполняем массив числами из файл
		while (i < n) {
			file >> a[i];
			i++;
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < n - (i + 1); j++) {
				if (a[j] > a[j + 1]) {
					flag = false;
					swap(a[j], a[j + 1]);
				}
			}
			if (flag) {
				break;
			}
		}
		i = 0;
		while (i < n) {
			cout << a[i] << " ";
			i++;
		}
		cout << endl;
		system("pause");
	}
}
