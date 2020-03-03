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
