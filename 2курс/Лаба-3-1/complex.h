#include <iostream>
using namespace std;
class complex
{
	float re, im;
public:
	complex(float inp_re = 0, float inp_im = 0);
	complex(const complex& copy);
	void output();
	void input(float i_re, float i_im);
	float module();
	complex operator+ (const complex& a);
	complex operator* (const complex& a);
	complex operator*(int n);
	bool operator== (complex& L);
	bool operator!= (complex& L);
	bool operator> (complex& L);
	bool operator< (complex& L);
	bool operator<= (complex& L);
	bool operator>= (complex& L);
	friend ostream& operator<< (ostream& out, const complex& c);
	friend istream& operator>> (istream& in, complex& c);
};

complex::complex(float inp_re, float inp_im) //Конструктор в который передают значения
{
	re = inp_re;
	im = inp_im;
}

complex::complex(const complex& copy) //Конструктор копирования
{
	re = copy.re;
	im = copy.im;
}

void complex::output() //Функция вывода
{
	if (re != 0) cout << re;
	if (im > 0 && im != 1) cout << "+" << im << "*i";
	if (im < 0 && im != -1) cout << im << "*i";
	if (im == 0 && re == 0) cout << "0";
	if (im == 1 && re != 0) cout << "+i";
	if (im == 1 && re == 0) cout << "i";
	if (im == -1) cout << "-i";
}

void complex::input(float i_re, float i_im)
{
	re = i_re;
	im = i_im;
}

float complex::module()
{
	return sqrt(re * re + im * im);
}

complex complex::operator+ (const complex& a)
{
	complex t;
	t.re = re + a.re;
	t.im = im + a.im;
	return t;
}

complex complex::operator* (const complex& a) 
{
	complex t;
	t.re = re * a.re - im * a.im;
	t.im = re * a.im + a.re * im;
	return t;
}

complex complex::operator*(int n)
{
	complex t;
	t.re = re * n;
	t.im = im * n;
	return t;
}

bool complex::operator== (complex& L)
{
	return module() == L.module();
}

bool complex::operator!= (complex& L)
{
	return module() != L.module();
}

bool complex::operator> (complex& L)
{
    return module() > L.module();
}

bool complex::operator< (complex& L)
{
	return module() < L.module();
}

bool complex::operator<= (complex& L)
{
	return module() <= L.module();
}

bool complex::operator>= (complex& L)
{
	return module() >= L.module();
}

ostream& operator<< (ostream& out, const complex& c)
{
	if (c.re != 0) out << c.re;
	if (c.im > 0 && c.im != 1) out << "+" << c.im << "*i";
	if (c.im < 0 && c.im != -1) out << c.im << "*i";
	if (c.im == 0 && c.re == 0) out << "0";
	if (c.im == 1 && c.re != 0) out << "+i";
	if (c.im == 1 && c.re == 0) out << "i";
	if (c.im == -1) out << "-i";
	return out;
}

istream& operator>> (istream& in, complex& c)
{
	in >> c.re;
	in >> c.im;
	return in;
}
