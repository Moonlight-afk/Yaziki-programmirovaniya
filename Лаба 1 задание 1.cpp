#include<iostream>
#include<math.h>
#include<fstream>
#include<string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n,k=0;
	cout << "Введите размер массива:";
	cin >> n;
	int *a = new int[n];
	fstream file;
	file.open("D:\\Work\\Ilya\\Project22\\massiv.txt");
	if (file.is_open()) {
		while (k < n) {
			a[k] = k;
			file << k << " ";
			k++;
		}
	}
	else {
		cout << "Файл не может быть открыт.";
	}
	string line;
	ifstream in("D:\\Work\\Ilya\\Project22\\massiv.txt");
	if (in.is_open()) {
		while (getline(in, line)) {
			cout << line;
		}
	}
	else {
		cout << "Файл не может быть открыт.";
	}
	in.close();
	system("pause");
}
