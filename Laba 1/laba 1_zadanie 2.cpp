#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int k, nehet;
	int b, a;
	int n = 0;
	//задаем интервал
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
		int* massiv = new int[20];
		while (n < 20) {
			massiv[n] = a + (rand() % (b - a + 1));
			n++;
		}
		//число которое будем вставлять после каждого нечетного элемента
		cout << "Введите число k:";
		cin >> k;
		n = 0;
		nehet = 0;
		//считаем сколько нечетных элементов
		while (n < 20) {
			if (massiv[n] % 2 != 0) {
				nehet += 1;
			}
			n++;
		}
		//увеличиваем массив
		int razmer = 20 + nehet;
		massiv = (int*)realloc(massiv, razmer * sizeof(int));
		//вставляем после каждого нечетного элемента число k и сдвигаем массив
		n = 0;
		while (n < razmer) {
			if (massiv[n] % 2 != 0) {
				for (int j = razmer - 1; j > n + 1; --j) {
					massiv[j] = massiv[j - 1];
				}
				massiv[n + 1] = k;
				++n;
			}
			n++;
		}
		//выводим получившийся массив
		n = 0;
		while (n < razmer) {
			cout << massiv[n] << " ";
			n++;
		}
		cout << endl;
		cout << "Нечетных элементов:" << nehet << endl;
		system("pause");
	}
}
