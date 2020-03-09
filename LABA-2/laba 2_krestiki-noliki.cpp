#include<iostream>
using namespace std;

char board[9] = { '-','-' ,'-' ,'-' ,'-' ,'-' ,'-' ,'-' ,'-' };
int i, j;
void board_cout() {
	cout << "#############" << endl;
	cout << "# 1 # 2 # 3 #" << endl;
	cout << "#############" << endl;
	cout << "# 4 # 5 # 6 #" << endl;
	cout << "#############" << endl;
	cout << "# 7 # 8 # 9 #" << endl;
	cout << "#############" << endl;
}

int move() {
	int nomer;
	cout << "#############" << endl;
	cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << endl;
	cout << "#############" << endl;
	cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << endl;
	cout << "#############" << endl;
	cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << endl;
	cout << "#############" << endl;
	cout << "В какую ячейку вы хотите поставить Х?-";
	cin >> nomer;
	while (nomer > 9 || nomer < 1) {
		cout << "Пожалуйста введите правильное число (1-9):";
		cin >> nomer;
	}
	return nomer;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int** a;
	int n = 3, m = 3,proverka;
	a = new int* [n];
	for (i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}
	/*int a11 = a[0][0];
	int a12 = a[0][1];
	int a13 = a[0][2];
	int a21 = a[1][0];
	int a22 = a[1][1];
	int a23 = a[1][2];
	int a31 = a[2][0];
	int a32 = a[2][1];
	int a33 = a[2][2];*/
	cout << "Массив:" << endl;
	for (i = 0; i < n; i++)
	{

		for (j = 0; j < m; j++)
			printf("%5d", a[i][j]);
		cout << endl;
	}
	board_cout();
	cout << endl;
	int nomer = move();
	board[nomer - 1] = 'X';
	if (nomer == 1) {
		a[0][0] = 1;
	}
	if (nomer == 2) {
		a[0][1] = 1;
	}
	if (nomer == 3) {
		a[0][2] = 1;
	}
	if (nomer == 4) {
		a[1][0] = 1;
	}
	if (nomer == 5) {
		a[1][1] = 1;
	}
	if (nomer == 6) {
		a[1][2] = 1;
	}
	if (nomer == 7) {
		a[2][0] = 1;
	}
	if (nomer == 8) {
		a[2][1] = 1;
	}
	if (nomer == 9) {
		a[2][2] = 1;
	}
	cout << "Массив:" << endl;
	for (i = 0; i < n; i++)
	{

		for (j = 0; j < m; j++)
			printf("%5d", a[i][j]);
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{

		for (j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				a[i][j] = 1;
				if (i ==0 && j == 0) {
					board[0] = 'O';
				}
				if (i == 0 && j == 1) {
					board[1] = 'O';
				}
				if (i == 0 && j == 2) {
					board[2] = 'O';
				}
				if (i == 1 && j == 0) {
					board[3] = 'O';
				}
				if (i == 1 && j == 1) {
					board[4] = 'O';
				}
				if (i == 1 && j == 2) {
					board[5] = 'O';
				}
				if (i == 2 && j == 0) {
					board[6] = 'O';
				}
				if (i == 2 && j == 1) {
					board[7] = 'O';
				}
				if (i == 2 && j == 2) {
					board[8] = 'O';
				}
				proverka = 1;
				break;
			}
		}
		if (proverka = 1)break;
	}

	///////////////////////////////
	for (int k = 1; k < 9; k++) {
		cout << "Массив:" << endl;
		for (i = 0; i < n; i++)
		{

			for (j = 0; j < m; j++)
				printf("%5d", a[i][j]);
			cout << endl;
		}
		board_cout();
		cout << endl;
		int nomer = move();
		board[nomer - 1] = 'X';
		if (nomer == 1) {
			a[0][0] = 1;
		}
		if (nomer == 2) {
			a[0][1] = 1;
		}
		if (nomer == 3) {
			a[0][2] = 1;
		}
		if (nomer == 4) {
			a[1][0] = 1;
		}
		if (nomer == 5) {
			a[1][1] = 1;
		}
		if (nomer == 6) {
			a[1][2] = 1;
		}
		if (nomer == 7) {
			a[2][0] = 1;
		}
		if (nomer == 8) {
			a[2][1] = 1;
		}
		if (nomer == 9) {
			a[2][2] = 1;
		}
		cout << "Массив:" << endl;
		for (i = 0; i < n; i++)
		{

			for (j = 0; j < m; j++)
				printf("%5d", a[i][j]);
			cout << endl;
		}
		proverka = 0;
		for (i = 0; i < n; i++)
		{

			for (j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					a[i][j] = 1;
					if (i == 0 && j == 0) {
						board[0] = 'O';
					}
					if (i == 0 && j == 1) {
						board[1] = 'O';
					}
					if (i == 0 && j == 2) {
						board[2] = 'O';
					}
					if (i == 1 && j == 0) {
						board[3] = 'O';
					}
					if (i == 1 && j == 1) {
						board[4] = 'O';
					}
					if (i == 1 && j == 2) {
						board[5] = 'O';
					}
					if (i == 2 && j == 0) {
						board[6] = 'O';
					}
					if (i == 2 && j == 1) {
						board[7] = 'O';
					}
					if (i == 2 && j == 2) {
						board[8] = 'O';
					}
					proverka = 1;
					break;
				}
			}
			if (proverka = 1)break;
		}
	}
	system("pause");
}
