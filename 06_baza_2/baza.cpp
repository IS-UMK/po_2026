#include "baza.h"
#include <algorithm>
#include <fstream>

using namespace std;

Baza& Baza::Dodaj(const Osoba& o)
{
	if (ile_elementow == rozmiar)
	{
		rozmiar = rozmiar * 2;
		Osoba *nowe_osoby = new Osoba[rozmiar];
		for (int i = 0; i < ile_elementow; i++)
		{
			nowe_osoby[i] = osoby[i];
		}
		delete[] osoby;
		this->osoby = nowe_osoby;
	}

	osoby[ile_elementow] = o;
	ile_elementow++;
	return *this;
}

Baza& Baza::Sortuj()
{
	sort(osoby, osoby + ile_elementow);
	return *this;
}

void Baza::Zapisz(const char* nazwa) const
{

	ofstream plik(nazwa);

	if (plik.is_open())
	{
		plik << *this;
		plik.close();
		cout << "Baza danaych zapisana w " << nazwa << endl;
	}
	else
	{
		cerr << "Blad odczytu pliku: " << nazwa << endl;
	}
}

Baza::~Baza()
{
	if (osoby != nullptr)
	{
		delete[] osoby;
		osoby = nullptr;
	}
	ile_elementow = 0;
	rozmiar = 0;
}

ostream& operator<<(ostream& o, const Baza& b)
{
	o << "Rozmiar: " << b.rozmiar << endl;
	o << "Liczba elementow: " << b.ile_elementow << endl;

	for (int i = 0; i < b.ile_elementow; i++)
	{
		o << i + 1 << " : " << b.osoby[i] << endl;
	}
	return o;
}
