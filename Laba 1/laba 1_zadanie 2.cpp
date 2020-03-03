#include"stdafx.h"
#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int chet = 0, i = 0, k = 0;
	//узнаем колличество чисел в файле
		char str[250];
		int count = 1;
		FILE *stream;
		errno_t err;
		err = fopen_s(&stream, "C:\\Users\\student\\Desktop\\massiv.txt", "r");
		if (err == 0)
		{
			fgets(str, 250, stream);
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] == ' ')
				{
					count++;
				}
			}
		}
		//создаем массив и заполняем его числами из файлов
		int* a = new int[count];
		ifstream file("C:\\Users\\student\\Desktop\\massiv.txt");
		i = 0;
		while (i < count) {
			 file >> a[i];
			i++;
		}
		cout << endl;
		//Вывод начального массива
		i = 0;
		cout << "Неотсортированный:" << endl;
		while (i < count) {
			cout << a[i] << " ";
			i++;
		}
		cout << endl;
		//Сортировка массива
		for (int i = 0; i < count; i++) {
			bool flag = true;
			for (int j = 0; j < count - (i + 1); j++) {
				if (a[j] > a[j + 1]) {
					flag = false;
					swap(a[j], a[j + 1]);
				}
			}
			if (flag) {
				break;
			}
		}
		//Узнаем скольно положительных элементов
		i = 0;
		while (i < count) {
			if (a[i] >= 0) {
				k++;
			}
			i++;
		}
		//Создаем новый1 массив размерностью положительных элементов и заполняем его 
		int* nov = new int[k];
		int j = 0;
		for (int i = 0; i < count; i++)
		{
			if (a[i] >= 0)
			{
				nov[j] = a[i];
				j++;
			}
		}
		//Вывод конечного массива
		cout << "Отсортированный:" << endl;
		i = 0;
		while (i < k) {
			cout << nov[i] << " ";
			i++;
		}
		cout << endl;
	
	system("pause");
}
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
