#pragma once
#include <iostream>

class Figure
{
public:
	Figure();
	virtual ~Figure() = 0;
	virtual void Show() = 0;
	virtual double CalcArea() = 0;

};
