#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include <cmath>
using namespace std;

Circle::Circle(int rad)
{
	r = 0;
	r = rad;
}

Circle::~Circle()
{
	//delete[] r;
}

void Circle::Show()
{
	cout << "------------------" << endl;
	cout << "Circle info: " << endl;
	cout << "\t r = " << r << endl;
	cout << "------------------" << endl;
}

double Circle::CalcArea()
{
	return  acos(-1) * r * r;
}

int Circle::Get_r()
{
	cout << "int Circle::Get_r() " << endl;
	return r;
}
