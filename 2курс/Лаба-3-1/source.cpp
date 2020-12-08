#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "complex.h"
using namespace std;
template<typename T>
class vector {
private:
	int size;// , m;
	T* v;
	void lloc();
public:
	vector() {}; // конструктор по умолчанию
	vector(const vector& t); // конструктор копирования
	~vector(); // деструктор
	vector(int n);
	float lenght(); // длина вектора
	void output(); // вывод результата
	void input(int n); // заполняем массив
	vector operator + (const vector& t); // сложение векторов
	//vector operator = (const vector& t);
	float operator * (vector<T>& t); // скалярное умножение векторов
	vector operator * (int a); // умножение вектора на число
	bool operator > (vector& c); // перегрузка для логического оператора больше
	bool operator < (vector& c); // перегрузка для логического оператора меньше
	bool operator == (vector& c); // перегрузка для логического оператора равно
	bool operator != (vector& c); // перегрузка для логического оператора не равно
	/*дружественные функции для ввода и вывода векторов*/
	template<typename T1> friend istream& operator >> (istream& s, vector<T1>& t);
	template<typename T1> friend ostream& operator << (ostream& s, vector<T1>& t);
};

template<typename T>
void vector<T>::lloc() //Функция создания массива
{
	v = new T[size];
}

template<>

void vector<complex>::lloc()
{
	v = new complex[size];
}

template<>
vector<complex>::vector(int n)
{
	size = n;
	complex();
	lloc();
}

template<typename T>

vector<T>::vector(int n) //Конструктор
{
	size = n;
	lloc();
}

template<>
vector<char>::vector(int n) //Конструктор
{
	size = n;
	char* v;
	//char* v = new char[size];
	v = new char[size];
}

template <typename T>
vector<T>::vector(const vector<T>& t) //Конструктор копирования
{
	/* Kонструктор копирования типа T */
	size = t.size;
	v = new T[size];
	for (int i = 0; i < size; i++)
		v[i] = t.v[i];
}

template<>

vector<char>::vector<char>(const vector<char>& t) //Конструктор копирования типа char
{
	/* Kонструктор копирования типа char* */
	size = t.size;
	//m = t.m;
	v = new char[size];
	for (int i = 0; i < t.size; i++)
		v[i] = t.v[i];
}

template<typename T>

vector<T>::~vector() //Диструктор
{
	/* Деструктор */
	delete[]v;
}

template<typename T>

float vector<T>::lenght() //Функция нахождения длины вектора типа T
{
	/*Определяем длину вектора типа T*/
	float t = 0;
	for (int i = 0; i < size; i++)
	{
		t = t + (v[i] * v[i]);
	}
	return t = sqrt(t);
}

template<typename T>

vector<T> vector<T> :: operator + (const vector& t) //Переопределение оператора сложения векторов
{
	/*Координаты суммы векторов равны суммам
	соответствующих координат слагаемых */
	vector c;
	c.size = t.size;
	c.v = new T[c.size];
	for (int i = 0; i < t.size; i++)
		c.v[i] = v[i] + t.v[i];
	return c;
}

template<typename T>

float vector<T> :: operator * (vector<T>& t) {
	/*Скалярным произведением векторов называется число,
	равное произведению длин этих векторов на косинус угла между ними*/
	vector t;
	t.size = size;
	t.v = new float[size];
	for (int i = 0; i < size; i++)
	{
		t.v[i] = v[i] * size;
	}
	return t;
}

/*template<>

vector<char*>vector<char*>::operator*(int a)

{

return 0;

}*/

template<>

vector<complex> vector<complex>::operator*(int a) //Оператор умножения 
{
	vector<complex> t;
	t.size = size;
	t.v = new complex[size];
	for (int i = 0; i < size; i++)
		t.v[i] = v[i].complex::operator*(a);
	return t;
}

template<typename T>

vector<T> vector<T>::operator*(int n) // Оператор умножения на число
{
	vector t;
	t.size = size;
	t.v = new T[size];
	for (int i = 0; i < size; i++)
	{
		t.v[i] = v[i] * n;
	}
	return t;

}

template<typename T>

void vector<T>::input(int n) {
	size = n;
	v = new T[size];
	cout << "Введите значения вектора: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> v[i];
	}
}

template<typename T>

void vector<T>::output() {
	for (int i = 0; i < size; i++)
		cout << v[i] << " ";
}

template<>

void vector<complex>::input(int n)
{
	int re_in = 0, im_in = 0;
	size = n;
	v = new complex[size];
	for (int i = 0; i < n; i++)
	{
		cin >> re_in;
		cin >> im_in;
		v[i].complex::input(re_in, im_in);
	}

}

template<>

void vector<complex>::output()
{
	for (int i = 0; i < size; i++)
	{
		//cout << v[i] << endl;
		v[i].complex::output();
		cout << endl;
	}

}

template<>

void vector<char>::output() {

	for (int i = 0; i < size; i++)

		cout << v[i] << " ";

}

template<>

void vector<char>::input(int n) {

	char* v;
	v = new char[n];
	size = n;
	cout << "Введите значения вектора: " << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

}

/*Операции равно, не равно, больше, меньше для типа T*/

template<typename T>

bool vector<T>::operator==(vector<T>& t) {

	return lenght() == t.lenght();

}

template<typename T>

bool vector<T>::operator!=(vector<T>& t) {

	return lenght() != t.lenght();

}

template<typename T>

bool vector<T>::operator>(vector<T>& t) {

	return lenght() > t.lenght();

}

template<typename T>

bool vector<T>::operator<(vector<T>& t) {

	return lenght() < t.lenght();

}

/*template<>

vector<char*>vector<char*>::operator+(const vector<char*>& t) //Переопределение оператора сложения векторов типа char

{

vector<char*> temp;

for (int i = 0; i < size; i++) {

strcpy(temp.v[i], v[i]);

strcat(temp.v[i], t.v[i]);

}

return temp;

}

template<>

float vector<char*>::lenght() //Функция нахождения длины вектора char

{

float char_l = 0;

for (int i = 0; i < size; i++)

char_l = char_l + strlen(v[i]);

return char_l;

}*/

/*Операции равно, не равно, больше, меньше для типа char* */

/*template<>

bool vector<char*>::operator==(vector<char*>& t) {

return lenght() == t.lenght();

}

template<>

bool vector<char*>::operator!=(vector<char*>& t) {

return lenght() != t.lenght();

}

template<>

bool vector<char*>::operator>(vector<char*>& t) {

return lenght() > t.lenght();

}

template<>

bool vector<char*>::operator<(vector<char*>& t) {

return lenght() < t.lenght();

}*/

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<int> a, b;
	vector<char>c, d;
	vector<complex> g;
	int n = 0, as = 0, xz = 0;
	cout << "Введите n:" << endl;
	cin >> n;
	cout << endl;
	a.input(n);
	b.input(n);
	cout << endl;
	a.output();
	b.output();
	cout << endl;
	cout << "Введите вектор типа complex: " << endl;
	g.input(n);
	cout << endl;
	g.output();
	cout << "Введите число на которое нужно умножить вектор: ";
	cin >> xz;
	cout << "Умножени вектора типа complex на число:" << endl;
	g.operator*(xz).output();
	cout << endl;
	cout << "Введите вектора типа char* " << endl;
	c.input(n);
	//c.output();
	//d.input(n);
	cout << "Результат сложения 2-х векторов: " << endl;
	a.vector<int>::operator+(b).output();
	cout << "<<< Умножение векторов на число >>>" << endl << "Введите число: ";
	cin >> n;
	a.vector<int>::operator*(n).output(); cout << endl;
	b.vector<int>::operator*(n).output(); cout << endl;
	if (a.operator==(b))
		cout << "Вектора равны" << endl;
	if (a.operator!=(b))
		cout << "Вектора неравны" << endl;
	if (a.operator>(b))
		cout << "Первый вектор больше второго" << endl;
	if (a.operator<(b))
		cout << "Первый вектор меньшего второго" << endl;
}
