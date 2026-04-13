#ifndef BAZA_H
#define BAZA_H

#include "osoba.h"
#include <iostream>
using namespace std;

class Baza {
private:
	int rozmiar;
	int ile_elementow;
	Osoba* osoby;
public:

	static const int ROZMIAR_DOMYSLNY = 100;

	Baza(int rozmiar = Baza::ROZMIAR_DOMYSLNY) :
		rozmiar{ rozmiar }, ile_elementow{ 0 },
		osoby{ new Osoba[rozmiar] } { }

	Baza& Dodaj(const Osoba& o);

	friend ostream& operator<<(ostream& o, const Baza& b);
	
	Baza& Sortuj();

	void Zapisz(const char* nazwa) const;

	~Baza();
};

ostream& operator<<(ostream& o, const Baza& b);
#endif