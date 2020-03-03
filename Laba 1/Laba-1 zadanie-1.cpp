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
	int* a = new int[100];
	//открываем файл
	ifstream file("C:\\Users\\student\\Desktop\\massiv.txt");
	if (!file) {
		cout << "Ошибка" << endl;
	}
	else {
		//заполняем массив числами из файл
		while (i < 100) {
			file >> a[i];
			i++;
		}
		cout << endl;
		i = 0;
		cout << "Неотсортированный:" << endl;
		while (i < 100) {
			cout << a[i] << " ";
			i++;
		}
		cout << endl;
		for (int i = 0; i < 100; i++) {
			bool flag = true;
			for (int j = 0; j < 100 - (i + 1); j++) {
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
		while (i < 100) {
			if (a[i] >= 0) {
				k++;
			}
			i++;
		}
		int* nov = new int[k];
		int j = 0;
		for (int i = 0; i < 100; i++)
		{
			if (a[i] >= 0)
			{
				nov[j] = a[i];
				j++;
			}
		}
		cout << "Отсортированный:" << endl;
		i = 0;
		while (i < k) {
			cout << nov[i] << " ";
			i++;
		}
		cout << endl;
	}
	system("pause");
}
