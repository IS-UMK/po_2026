#ifndef GAUSS_H
#define GAUSS_H

#include <iostream>
using namespace std;

#include "funkcja.h"

class Gauss : public Funkcja
{
private:
	double srednia;
	double odchylenie;

public:
	Gauss(double srednia = 0.0, double odchylenie = 1.0)
		:srednia{ srednia }, odchylenie{ odchylenie } { }

	virtual double ObliczWartosc(double x) const override;

	friend ostream& operator<<(ostream& o, const Gauss& g);

};




#endif