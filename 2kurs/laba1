#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<time.h>
#include<ctime>
#include<Windows.h>

using namespace std;

struct dateTime {
	int day{ 1 };
	int month{ 1 };
	int year{ 1970 };

	int hour{ 0 };
	int minute{ 0 };
	int second{ 0 };

	void getdateTime();
};

void dateTime::getdateTime()
{
	std::cout <<
		std::setfill('0') <<
		std::setw(2) << day << '.' <<
		std::setw(2) << month << '.' <<
		std::setw(4) << year << ' ' <<
		std::setw(2) << hour << ':' <<
		std::setw(2) << minute << ':' <<
		std::setw(2) << second;
}

dateTime systemTime()
{
	time_t t = std::time(0);
	tm* now = std::localtime(&t);

	dateTime sysTime = {
		now->tm_mday,
		now->tm_mon + 1,
		now->tm_year + 1900,
		now->tm_hour,
		now->tm_min,
		now->tm_sec
	};

	return sysTime;
}

struct Datetime
{
	string month = " ";
	string year = " ";
	string seconds = " ";
	string minutes = " ";
	string houns = " ";
	string day = " ";
	void method() {
		cout << day << "." << month << "." << year << " " << houns << ":" << minutes << ":" << seconds << " ";
		cout << " Предыдущий день:";
		int d = atoi(day.c_str());
		int m = atoi(month.c_str());
		int y = atof(year.c_str());
		//если пролучается предыдущий месяц на 31 число
		if (d == 1) {
			if (m - 1 == 1 || m - 1 == 3 || m - 1 == 5 || m - 1 == 7 || m - 1 == 8 || m - 1 == 10 || m == 1) {
				d = 31;
				if (m == 1) {
					m = 12;
					y = y - 1;
				}
				else {
					m = m - 1;
				}
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			//если пролучается предыдущий месяц на 30 число
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			//весокосный год
			if (y % 4 == 0 && m == 3) {
				d = 29;
				m = m - 1;
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			//не високосный год
			else {
				if (y % 4 != 0 && m == 3) {
					d = 30;
					m = m - 1;
					cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
				}
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (m - 1 == 4 || m - 1 == 6 || m - 1 == 9 || m - 1 == 11) {
				d = 30;
				m = m - 1;
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
		}
		else {
			cout << d - 1 << "." << month << "." << year << " " << houns << ":" << minutes << ":" << seconds;
		}
		cout << " Следующий день:";
		d = atoi(day.c_str());
		m = atoi(month.c_str());
		y = atoi(year.c_str());
		if (d == 31 || d == 30 || d == 29) {
			if (d == 31 && m == 12) {
				d = 1;
				m = 1;
				y = y + 1;
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 31 && m != 12) {
				d = 1;
				m = m + 1;
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
				d = 1;
				m = m + 1;
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 30 && m == 2 && y % 4 != 0) {
				d = 1;
				m = m + 1;
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 29 && m == 2 && y % 4 == 0) {
				d = 1;
				m = m + 1;
				cout << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
		}
		else {
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			d = d + 1;
			cout << d << "." << month << "." << year << " " << houns << ":" << minutes << ":" << seconds << endl;
		}
	}
		/*d = atoi(day.c_str());
		m = atoi(month.c_str());
		y = atoi(year.c_str());
		if ((d != 31 && m!=12) || (d != 30 ) || (d != 29 && m != 2 && y % 4 != 0)) {
			cout<<" !1! " << d + 1 << "." << month << "." << year << " " << houns << ":" << minutes << ":" << seconds << endl;
		}
		if (d != 31 && m != 12) {
			cout << " !1! " << d + 1 << "." << month << "." << year << " " << houns << ":" << minutes << ":" << seconds << endl;
		}
		if (d != 30) {
			cout << " !11! " << d + 1 << "." << month << "." << year << " " << houns << ":" << minutes << ":" << seconds << endl;
		}
		if (d != 29 && m != 2) {
			cout << " !12! " << d + 1 << "." << month << "." << year << " " << houns << ":" << minutes << ":" << seconds << endl;
		}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if ((y % 4 == 0 && d == 29 && m == 2) || (y % 4 != 0 && d == 30 && m == 2)) {
				d = 1;
				m = m + 1;
				cout << " !2! " << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 31 && m == 12) {
				m = 1;
				d = 1;
				y = y + 1;
				cout << " !3! " << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if ((d == 30 || d == 31) && (m != 12||m!=2)) {
				m = 1;
				d = 1;
				cout << " !4! " << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds << endl;
			}
	}*/
	void var5() {
		int d = atoi(day.c_str());
		int m = atoi(month.c_str());
		int y = atof(year.c_str());
		//если пролучается предыдущий месяц на 31 число
		if (d == 1) {
			if (m - 1 == 1 || m - 1 == 3 || m - 1 == 5 || m - 1 == 7 || m - 1 == 8 || m - 1 == 10 || m == 1) {
				d = 31;
				if (m == 1) {
					m = 12;
					y = y - 1;
				}
				else {
					m = m - 1;
				}
				cout << " На предыдущий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			//если пролучается предыдущий месяц на 30 число
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			//весокосный год
			if (y % 4 == 0 && m == 3) {
				d = 29;
				m = m - 1;
				cout << " На предыдущий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			//не високосный год
			else {
				if (y % 4 != 0 && m == 3) {
					d = 30;
					m = m - 1;
					cout << " На предыдущий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
				}
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (m - 1 == 4 || m - 1 == 6 || m - 1 == 9 || m - 1 == 11) {
				d = 30;
				m = m - 1;
				cout << " На предыдущий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
		}
		d = atoi(day.c_str());
		m = atoi(month.c_str());
		y = atoi(year.c_str());
		if (d == 31 || d == 30 || d == 29) {
			if (d == 31 && m == 12) {
				d = 1;
				m = 1;
				y = y + 1;
				cout << " На следующий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 31 && m != 12) {
				d = 1;
				m = m + 1;
				cout << " На следующий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
				d = 1;
				m = m + 1;
				cout << " На следующий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 30 && m == 2 && y % 4 != 0) {
				d = 1;
				m = m + 1;
				cout << " На следующий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
			d = atoi(day.c_str());
			m = atoi(month.c_str());
			y = atoi(year.c_str());
			if (d == 29 && m == 2 && y % 4 == 0) {
				d = 1;
				m = m + 1;
				cout << " На следующий месяц:" << d << "." << m << "." << y << " " << houns << ":" << minutes << ":" << seconds;
			}
		}
	}
	
};

struct Timedelta
{
	int day;
	int mon;
	int year;
	int seconds;
	int minutes;
	int houns;
};

/*struct datetime {
	void sysTime() {
		time_t now = time(0);
		char* dt = ctime(&now);
		cout << "Локальная дата и время:" << dt << endl;
	}
};*/

int main() {
	setlocale(LC_ALL, "RUS");
	int size = 0;
	string s;
	string x;
	Datetime day1;
	ifstream file;
	//datetime time;
	file.open("C:\\Users\\стас\\Desktop\\Денис\\ЯП-практика\\date.txt");
	if (!file.is_open()) {
		cout << "Файл не найден!" << endl;
	}
	else {
		while (getline(file, s))
		{
			size++;
		}
		file.close();
		file.open("C:\\Users\\стас\\Desktop\\Денис\\ЯП-практика\\date.txt");
		Datetime* arr = new Datetime[size];
		for (int i = 0; i < size; i++)
		{
			getline(file, x);
			istringstream ss(x);
			ss >> day1.day >> day1.month >> day1.year >> day1.houns >> day1.minutes >> day1.seconds;
			arr[i] = day1;
			cout << "[" << i + 1 << "]";
			day1.method();
		}
		cout << "Даты выпадающие на следующий или предыдущий месяц:" << endl;
		file.seekg(0);
		for (int i = 0; i < size; i++)
		{
			getline(file, x);
			istringstream ss(x);
			ss >> day1.day >> day1.month >> day1.year >> day1.houns >> day1.minutes >> day1.seconds;
			arr[i] = day1;
			cout<<endl << "[" << i + 1 << "]";
			day1.var5();
		}
	}
	cout << endl << "Текущая дата и время:" << endl;
	//time.sysTime();
	dateTime currentTime = systemTime();
	currentTime.getdateTime();

	std::cout << std::endl;
    system("pause");
}
