#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");

	int n, m, ** A, i, j, a, b;

	cout << "Введите число столбцов матрицы:";
	cin >> m;
	cout << "Введите число строк матрицы:";
	cin >> n;
	if (m != n) {
		while (m != n) {
			cout << "Матрица должна быть квадратная!" << endl;
			cout << "Введите число столбцов матрицы:";
			cin >> m;
			cout << "Введите число строк матрицы:";
			cin >> n;
		}
	}
	cout << "Введите минимальный элемент который может содержать матрица:";
	cin >> a;
	if (a >= 0) {
		while (a >= 0) {
			cout << "Минимальный элемент который может содержать матрица должен быть отрицательным!" << endl;
			cout << "Введите минимальный элемент который может содержать матрица:";
			cin >> a;
		}
	}
	cout << "Введите максимальный элемент который может содержать матрица:";
	cin >> b;
	if (b <= 0) {
		while (b <= 0) {
			cout << "Максимальный элемент который может содержать матрица должен быть положительным!" << endl;
			cout << "Введите максимальный элемент который может содержать матрица:";
			cin >> b;
		}
	}

	//создаем и заполняем матрицу случайными числами из диапозона [a,b]
	A = new int* [n];
	for (i = 0; i < n; i++) {
		A[i] = new int[m];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			A[i][j] = rand() % (b - a + 1) + a;
		}
	}

	//выводим матрицу
	for (i = 0; i < n; i++)
	{

		for (j = 0; j < m; j++)
			printf("%5d", A[i][j]);
		cout << endl;
	}

	//находим максимальный отрицательный элемент в нужной зоне
	int maxotr = -999999;
	int imaxotr, jmaxotr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i > j) && (i > n - 1 - j))
				if ((A[i][j] > maxotr) && (A[i][j] < 0)) {
					maxotr = A[i][j];
					//запоминаем i и j
					imaxotr = i;
					jmaxotr = j;
				}
		}
	}
	//cout << imaxotr << endl;
	//cout << jmaxotr << endl;

	//находим минимальный положительный элемент в нужной зоне
	int minpol = 999999;
	int iminpol, jminpol;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i < n - 1 - j) && (i > j))
				if ((A[i][j] < minpol) && (A[i][j] > 0)) {
					minpol = A[i][j];
					//запоминаем i и j
					iminpol = i;
					jminpol = j;
				}
		}
	}
	if (minpol == 999999) {
		cout << "В заданном участке матрицы нет положительных чисел, попробуйте еще раз" << endl;
		system("pause");
		exit(0);
	}
	if (maxotr == -999999) {
		cout << "В заданном участке матрицы нет отрицательных чисел, попробуйте еще раз" << endl;
		system("pause");
		exit(0);
	}
	else {
		cout << "Максимальный отрицательный:" << maxotr << endl;
		cout << "Минимальный положительный:" << minpol << endl;

		//меняем элементы местами
		int k;
		k = A[imaxotr][jmaxotr];
		A[imaxotr][jmaxotr] = A[iminpol][jminpol];
		A[iminpol][jminpol] = k;

		//выводим измененную матрицу
		for (i = 0; i < n; i++)
		{

			for (j = 0; j < m; j++)
				printf("%5d", A[i][j]);
			cout << endl;
		}
	}
	system("pause");
}
