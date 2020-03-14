#include<iostream>
#include <cstdlib>

char board[9] = { '-','-' ,'-' ,'-' ,'-' ,'-' ,'-' ,'-' ,'-' };
int i, j;

//функция вывода возможных ходов
void board_cout() {
	std::cout << "#############" << std::endl;
	std::cout << "# 1 # 2 # 3 #" << std::endl;
	std::cout << "#############" << std::endl;
	std::cout << "# 4 # 5 # 6 #" << std::endl;
	std::cout << "#############" << std::endl;
	std::cout << "# 7 # 8 # 9 #" << std::endl;
	std::cout << "#############" << std::endl;
}


//функция вывода доски с ходами
int move() {
	int nomer;
	std::cout << "#############" << std::endl;
	std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
	std::cout << "#############" << std::endl;
	std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
	std::cout << "#############" << std::endl;
	std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
	std::cout << "#############" << std::endl;
	std::cout << "В какую ячейку вы хотите поставить Х?-";
	std::cin >> nomer;
	while (nomer > 9 || nomer < 1||board[nomer-1]!='-') {
		std::cout << "Пожалуйста введите правильное число (1-9):";
		std::cin >> nomer;
	}
	return nomer;
}


using namespace std;


int main() {
	setlocale(LC_ALL, "RUS");
	int** a;
	int n = 3, m = 3, proverka;

	//задаем массив и заполняем нулями
	a = new int* [n];
	for (i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}

	//вызываем 2 функции и выбираем ход
	board_cout();
	cout << endl;
	int nomer = move();
	board[nomer - 1] = 'X'; //поставит Х в выбранную область

	//условия для заполнения массива
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

	//сканируем массив первый раз
	for (i = 0; i < n; i++)
	{

		for (j = 0; j < m; j++) {
			//если находим ноль, то вместо него ставим единицу и в игральное поле ставиться О
			if (a[i][j] == 0) {
				a[i][j] = 1;

				//условия чтобы ноль встал на нужное место
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
				proverka = 1; //проверна нужна чтобы выходить из цикла
				break;
			}
		}
		if (proverka = 1)break;
	}


	//главный цикл заполнения поля нулями и крестиками
	for (int k = 1; k < 5; k++) {
		system("cls");  //очищаем терминал
		proverka = 0;   //зануляем проверку каждый раз


		//повтореня действий описанных выше
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


		//каждый раз после хода крестиками идет проверка выиграша
		if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}
		if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}
		if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}
		if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}
		if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}
		if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}
		if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}
		if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
			system("cls");
			system("color 2");
			cout << "Выиграли крестики!" << endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
			std::cout << "#############" << std::endl;
			system("pause");
			exit(0);
		}


		//сканирование массива, чтобы в пустую область компьютер поставил нолик
		if (proverka == 0) {
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


						//проверка на выигрыш после хода ноликами
						if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}
						if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}
						if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}
						if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}
						if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}
						if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}
						if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}
						if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
							system("cls");
							system("color 2");
							cout << "Выиграли нолики!" << endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							std::cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << std::endl;
							std::cout << "#############" << std::endl;
							system("pause");
							exit(0);
						}


						proverka = 1;

					}
					if (proverka == 1)break;
				}
				if (proverka == 1)break;
			}
		}
	}

	//если никто не выиграл, очищается терминал и выводится получившееся поле
	system("cls");
	system("color 2");
	cout << "#############" << endl;
	cout << "# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << endl;
	cout << "#############" << endl;
	cout << "# " << board[3] << " # " << board[4] << " # " << board[5] << " # " << endl;
	cout << "#############" << endl;
	cout << "# " << board[6] << " # " << board[7] << " # " << board[8] << " # " << endl;
	cout << "#############" << endl;
	cout << "Ничья" << endl;
	system("pause");
}
