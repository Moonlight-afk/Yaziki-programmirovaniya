#include"stdafx.h"
#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int k, nehet;
	int b, a,razmer;
	int n = 0;
	//задаем интервал
	cout << "Введите размер массива:";
	cin >> razmer;
	cout << "Введите минимальный элемент массива:";
	cin >> a;
	cout << "Введите максимальный элемент массива:";
	cin >> b;
	if (a > b) {
		while (a > b) {
			cout << "Некоректный ввод" << endl;
			cout << "Введите минимальный элемент массива:";
			cin >> a;
			cout << "Введите максимальный элемент массива:";
			cin >> b;
		}
	}
	else {
		//создаем и заполняем массив случайными числами
		int* massiv = new int[razmer];
		while (n < razmer) {
			massiv[n] = a + (rand() % (b - a + 1));
			n++;
		}
		while (n < razmer) {
			cout << massiv[n] << " ";
			n++;
		}
		cout << endl;
		//число которое будем вставлять после каждого нечетного элемента
		cout << "Введите число k:";
		cin >> k;
		n = 0;
		nehet = 0;
		//считаем сколько нечетных элементов
		while (n < razmer) {
			if (massiv[n] % 2 != 0) {
				nehet += 1;
			}
			n++;
		}
		//увеличиваем массив
		int razmernov = razmer + nehet;
		massiv = (int*)realloc(massiv, razmernov * sizeof(int));
		//вставляем после каждого нечетного элемента число k и сдвигаем массив
		n = 0;
		while (n < razmernov) {
			if (massiv[n] % 2 != 0) {
				for (int j = razmernov - 1; j > n + 1; --j) {
					massiv[j] = massiv[j - 1];
				}
				massiv[n + 1] = k;
				++n;
			}
			n++;
		}
		//выводим получившийся массив
		n = 0;
		while (n < razmernov) {
			cout << massiv[n] << " ";
			n++;
		}
		cout << endl;
		cout << "Нечетных элементов:" << nehet << endl;
		system("pause");
	}
}
