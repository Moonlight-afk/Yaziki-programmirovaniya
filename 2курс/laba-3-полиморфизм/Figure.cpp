#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Home.h"
using namespace std;

Figure::Figure()
{
    cout << "Figure::Figure() \n" << endl;
}

Figure::~Figure()
{
    cout << "Figure::~Figure() \n" << endl;
}

int main()
{
    int rad1 = 0, dl = 0, sh = 0, n = 0, rad2 = 0, Hei1 = 0, Hei2 = 0;
    cout << "N = ";
    cin >> n;
    Figure* f;

    if (n == 1)
    {
        cout << "Radius = ";
        cin >> rad1;
        f = new Circle(rad1);
        cout << "------------------" << endl;
        f->Show();
        cout << "------------------" << endl;
        cout << "CalcArea: " << f->CalcArea() << endl;
        cout << "------------------" << endl;
    }

    if (n == 2)
    {
        cout << "Dlina: ";
        cin >> dl;
        cout << "Shirina: ";
        cin >> sh;
        f = new Rectangle(dl, sh);
        cout << "------------------" << endl;
        f->Show();
        cout << "------------------" << endl;
        cout << "CalcArea: " << f->CalcArea() << endl;
        cout << "------------------" << endl;
    }

    if (n == 0)
    {
        cout << "Dlina: ";
        cin >> dl;
        cout << "Shirina: ";
        cin >> sh;
        cout << "Radius window = ";
        cin >> rad1;
        cout << "Height = ";
        cin >> Hei1;
        cout << "Height window = ";
        cin >> Hei2;
        f = new Home(Hei1, Hei2, dl, sh, rad1);
        cout << "------------------" << endl;
        f->Show();
        cout << "------------------" << endl;
        cout << "CalcArea: " << f->CalcArea() << endl;
        cout << "------------------" << endl;
    }
}
