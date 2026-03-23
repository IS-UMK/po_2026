#include "wielomian.h"


Wielomian::Wielomian():Wielomian(0)
{
	wsp[0] = 0.0;
}

Wielomian::Wielomian(int st, const double* wsp):Wielomian(st)
{
	//this->st = st;
	//this->wsp = new double[st + 1];
	for (int i = 0; i < st+1; i++)
	{
		this->wsp[i] = wsp[i];
	}
}

Wielomian::Wielomian(int st) : st{ st }, wsp{ new double[st + 1] }
{

}

Wielomian::~Wielomian()
{
	if (wsp)
	{
		delete[] wsp;
		wsp = nullptr;
	}
}

Wielomian& Wielomian::operator=(const Wielomian& w)
{
	if (st != w.st)
	{
		delete[] wsp;
		wsp = new double[w.st];
		st = w.st;
	}
	for (int i = 0; i < w.st+1; i++) wsp[i] = w.wsp[i];

	return *this;
}

double& Wielomian::operator[](int i)
{
	return wsp[i];
}


Wielomian::Wielomian(const Wielomian& w) :Wielomian(w.st, w.wsp)
{

}

Wielomian Dodaj(const Wielomian& a, const Wielomian& b)
{
	/*
	int max_st = (a.st < b.st) ? b.st : a.st;
	Wielomian w(max_st);

	for (int i = 0; i < max_st+1; i++) w.wsp[i] = 0.0;
	for (int i = 0; i < a.st + 1; i++) w.wsp[i] = a.wsp[i];
	for (int i = 0; i < b.st + 1; i++) w.wsp[i] += b.wsp[i];
	return w;*/

	return a + b;
}

void Wielomian::Wypisz()
{
	/*
	cout << "f(x) = ";
	for (int i = st; i > 0; i--)
	{
		cout << fixed << setprecision(2) << wsp[i] << " x^" << i << " + ";
	}
	cout << wsp[0];
	*/

	cout << *this;
}

ostream& operator<<(ostream& o, const Wielomian& w)
{
	o << "f(x) = ";
	for (int i = w.st; i > 0; i--)
	{
		o << fixed << setprecision(2) << w.wsp[i] 
			<< " x^" << i << " + ";
	}
	o << w.wsp[0];
	return o;
}


Wielomian operator+(const Wielomian& a, const Wielomian& b)
{
	int max_st = (a.st < b.st) ? b.st : a.st;
	Wielomian w(max_st);

	for (int i = 0; i < max_st + 1; i++) w.wsp[i] = 0.0;
	for (int i = 0; i < a.st + 1; i++) w.wsp[i] = a.wsp[i];
	for (int i = 0; i < b.st + 1; i++) w.wsp[i] += b.wsp[i];
	return w;
}

