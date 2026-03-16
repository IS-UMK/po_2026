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

void Wielomian::Wypisz()
{
	cout << "f(x) = ";
	for (int i = st; i > 0; i--)
	{
		cout << fixed << setprecision(2) << wsp[i] << " x^" << i << " + ";
	}
	cout << wsp[0];
}

Wielomian::Wielomian(const Wielomian& w) :Wielomian(w.st, w.wsp)
{

}

Wielomian Dodaj(const Wielomian& a, const Wielomian& b)
{
	int max_st = (a.st < b.st) ? b.st : a.st;
	Wielomian w(max_st);

	for (int i = 0; i < max_st+1; i++) w.wsp[i] = 0.0;
	for (int i = 0; i < a.st + 1; i++) w.wsp[i] = a.wsp[i];
	for (int i = 0; i < b.st + 1; i++) w.wsp[i] += b.wsp[i];
	return w;
}
