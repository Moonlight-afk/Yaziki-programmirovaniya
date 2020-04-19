#include<iostream>


using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int n, m, vistrel;
	cout << "Введиет колличество игроков:";
	cin >> n;
	cout << "Введите колличество выстрелов:";
	cin >> m;
	int** mass = new int* [n];
		for(int i = 0; i < n; i++) {
			mass[i] = new int[m];
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << "Введите число от 0 до 10, игроку " << i+1 << ", выстрел " << j+1 << ":";
				cin >> mass[i][j];
			}
		}
		cout << endl;*/
		for (int i = 1; i <= m; i++) {
		cout << "        Выстрeл " << i;
	    }
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << "Игрок " << i+1 << "|    ";
			for (int j = 0; j < m; j++) {
				mass[i][j] = rand() % 10 + 1;
				cout << mass[i][j] << "               ";
			}
			cout << endl;
		}
		int s;
		int *n1 = new int[n];
		for (int i = 0; i < n; i++)
		{
			s = 0;
			for (int j = 0; j < m; j++)
				s += mass[i][j];
			n1[i] = s;
		}
		cout << "\nРезультаты: ";
		for (int i = 0; i < n; i++)
			cout << n1[i] << " ";

		int max, maxI,k,maxsum=0;
		max = 0;
		for (int f = 0; f < 2; f++) {
			k = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (mass[i][j] >= max) {
						max = mass[i][j];
						maxI = i;
						k++;
					}
				}
			}
		}
		cout << "\nПОБЕДИТЕЛЬ:\n";
		if (k == 1) {
			//cout << "Номер стрелка " << maxI+1 << endl;
		}
		else {
			for (int f = 0; f < 2; f++) {
				k = 0;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (mass[i][j] == max && n1[i] >= maxsum) {
							maxsum = n1[i];
							maxI = i;
							k++;
						}
					}
				}
			}
		}
		if (k == 1) {
			cout << "Номер стрелка " << maxI + 1 << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (mass[i][j] == max && n1[i] == maxsum) {
						cout << "Номер стрелка " << i + 1 << endl;
					}
				}
			}
		}
	system("pause");
}
