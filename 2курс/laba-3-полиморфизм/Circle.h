#pragma once
#include <iostream>
#include "Figure.h"
class Circle : public Figure
{
	int r;
public:
	Circle();
	Circle(int);
	virtual ~Circle();
	virtual void Show();
	virtual double CalcArea();
	int Get_r();
};
