#pragma once
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure
{
	int a, b;
public:
	Rectangle();
	Rectangle(int, int);
	virtual ~Rectangle();
	virtual void Show();
	virtual double CalcArea();
	int Get_a();
	int Get_b();
};
