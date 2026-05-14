#include "wielomian.h"

#ifndef PARABOLA_H
#define PARABOLA_H

class Parabola: public Wielomian
{
protected:
	double delta;

public:
	Parabola(double a = 0.0, double b = 0.0,
		double c = 0.0);
	double Ekstremum() const;
	void Wypisz() const { cout << "To jest parabola"; }
	int Pierwiastki(double* x1, double* x2) const;
	double ObliczWartosc(double x) const
	{
		return x * ( wsp[2] * x + wsp[1] ) + wsp[0];
	}
};

class Parabola2 : public Parabola
{
public:
	Parabola2(double a = 0.0, double b = 0.0, 
		double c = 0.0):Parabola(a, b, c) {}

	int Pierwiastki(double* x1, double* x2) const;
};

#endif

