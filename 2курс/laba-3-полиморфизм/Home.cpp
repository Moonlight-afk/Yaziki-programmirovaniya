#include <iostream>
#include "Figure.h"
#include "Home.h"
#include "Circle.h"
#include "Rectangle.h"
#include <cmath>
using namespace std;

Home::Home(int Hei1, int Hei2, int dl, int sh, int rad2)
{
	HeiHome = 0;
	HeiRoof = 0;
	radW = 0;
	Dl = 0;
	Sh = 0;
	HeiHome = Hei1;
	HeiRoof = Hei2;
	radW = rad2;
	Dl = dl;
	Sh = sh;
}

Home::~Home()
{
	//delete[] r;
}

void Home::Show()
{
	cout << "------------------" << endl;
	cout << "Circle info: " << endl;
	//cout << "\t r = " << r << endl;
	cout << "------------------" << endl;
}

double Home::CalcArea()
{
	double itog = 0, c = 0;
	Figure* f;
	f = new Rectangle(Dl, HeiHome);
	itog += f->CalcArea();
	f = new Rectangle(Sh, HeiHome);
	itog += 2 * (f->CalcArea());
	f = new Circle(HeiHome / 2);
	itog -= f->CalcArea();
	itog += (acos(-1) * HeiHome * Dl);
	itog += 4 * (HeiRoof * (Sh / 2));
	f = new Circle(radW);
	itog += f->CalcArea();
	c = sqrt((Sh / 2) * (Sh / 2) + Dl * Dl);
	f = new Rectangle(Dl, c);
	itog += 2 * (f->CalcArea());
	return itog;
}
