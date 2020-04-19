#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int chet=0, n,i=0, k = 0;
	cout << "Введите размер массива:";
	cin >> n;
	if (n < 5) {
		while (n<5) {
			cout << "Некорректный ввод" << endl;
			cout << "Введите размер массива:";
			cin >> n;
		}
	}
	
		int *a = new int[n];
		/*FILE* fin = NULL;
		fin = fopen("D:\\Work\\Ilya\\Project22\\massiv.txt","r");
		//ifstream newFile("D:\\Work\\Ilya\\Project22\\massiv.txt");
		if (!fin) {
			cout << "Ошибка" << endl;
		}
		else {
			while (i < n) {
				fscanf(fin, "%d", &a[i]);
				i++;
			}
		}
		fclose(fin);*/
		ifstream out("D:\\Work\\Ilya\\Project22\\massiv.txt", ios::out);
		if (!out) {
			cout << "Ошибка" << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				out.read((char*)&a[i], sizeof(i));
				out.close();
				char ch = getchar();
			}
		}
		i = 0;
		while (i < n) {
			if (a[i] >= 0) {
				chet++;
			}
			i++;
		}
		i = 0;
		int m = 0;
		int *nov = new int[chet];
		while (i < n) {
			if (a[i] >= 0) {
				nov[m] = a[i];
				m++;
			}
			i++;
		}
		m = 0;
		while (m < chet) {
			cout << nov[m];
			i++;
		}
	
}
