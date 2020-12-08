#pragma once
#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"

class Home : public Figure
{
	int HeiHome, HeiRoof, radW, Dl, Sh;
public:
	Home();
	Home(int, int, int, int, int);
	virtual ~Home();
	virtual void Show();
	virtual double CalcArea();
	int Get_a();
	int Get_b();
};
