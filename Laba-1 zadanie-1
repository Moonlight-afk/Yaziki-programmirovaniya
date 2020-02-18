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
	ofstream newFile;
	newFile.open("D:\\Work\\Ilya\\Project22\\massiv.txt");
	if (newFile.is_open()) {
		while (k < n) {
			a[k] = k;
			newFile << k << endl;
			k++;
		}
	}
	else {
		cout << "Файл не может быть открыт.";
	}
	string line;
	ifstream in("D:\\Work\\Ilya\\Project22\\massiv.txt");
	while (!in.eof())
	{
		getline(in, line);
		cout << line << endl;
	}
	system("pause");
}
