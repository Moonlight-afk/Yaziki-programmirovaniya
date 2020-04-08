#include<iostream>
#include<fstream>
#include <cstdlib>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int n, m, ** A, ** C, i, j;
	ifstream file;
	cout << "Введите число строк и столбцов которые будут содержать матрицы:" << endl;
	cout << "Строк:";
	cin >> m;
	cout << "Столбцов:";
	cin >> n;
	A = new int* [n];
	C = new int* [m];
	int* B = new int[n];
	int* D = new int[m];
	file.open("C:\\Users\\стас\\Desktop\\massiv.txt");
	if (!file.is_open()) {
		cout << "Файл не может быть открыт";
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[m];
	}
	cout << "Матрица А:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file >> A[i][j];
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "умножение матрицы на 2" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 2 * A[i][j];
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Матрица С:" << endl;
	for (int i = 0; i < m; i++)
	{
		C[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file >> C[i][j];
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Вектор В:" << endl;
	for (i = 0; i < n; i++) {
		file >> B[i];
		cout << B[i] << endl;
	}
	cout << endl;
	cout << "Вектор D:" << endl;
	for (i = 0; i < m; i++) {
		file >> D[i];
		cout << D[i] << endl;
	}
	cout << endl;
	cout << "Транспонированный вектор D:" << endl;
	for (i = 0; i < m; i++) {
		cout << D[i] << " ";
	}
	cout << endl;
	cout << "Умножение вектора D на матрицу С:" << endl;
	int* E = new int[n];
	for (i = 0; i < n; i++) {
		E[i] = 0;
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			E[i] = E[i] + (C[j][i] * D[j]);
		}
		cout << E[i] << " ";
	}
	cout << endl;
	cout << "Умножение вектора В на полученную матрицу Е:" << endl;
	int** F = new int* [n];
	for (int i = 0; i < n; i++)
	{
		F[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			F[i][j] = B[i] * E[j];
			cout << F[i][j] << "\t";
		}
		cout << endl;
	}
	
	cout << "Ответ:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = A[i][j] + F[i][j];
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
}

