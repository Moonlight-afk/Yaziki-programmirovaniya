#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include <cmath>
using namespace std;

Rectangle::Rectangle(int dl, int Sh)
{
	a = 0;
	b = 0;
	a = dl;
	b = Sh;
}

Rectangle::~Rectangle()
{
	//delete[] a;
	//delete[] b;
}

void Rectangle::Show()
{
	cout << "------------------" << endl;
	cout << "Rectangle info: " << endl;
	cout << "\t a = " << a << endl;
	cout << "\t b = " << b << endl;
	cout << "------------------" << endl;
}

double Rectangle::CalcArea()
{
	return a * b;
}

int Rectangle::Get_a()
{
	cout << " \n";
	return a;
}

int Rectangle::Get_b()
{
	cout << " \n";
	return b;
}
