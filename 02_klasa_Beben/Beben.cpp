#include "Beben.h"
#include <algorithm>

Beben::Beben(int rozmiar)
{
	this->rozmiar = rozmiar;
	this->kule = new int[rozmiar];
	opis = "Beben utworzony";
}

void Beben::Wypisz(int k)
{
	cout << "Rozmiar: " << rozmiar << endl;
	cout << "Opis: " << opis << endl;
	cout << "Kule: ";
	for (int i = 0; i < k; i++)
	{
		cout << " " << kule[i];
	}
	cout << "\n";
}

Beben& Beben::Wypelnij()
{
	for (int i = 0; i < rozmiar; i++)
	{
		kule[i] = i + 1;
	}
	opis = "Beben wypelniony";
	return *this;
}

Beben& Beben::Mieszaj()
{
	random_shuffle(kule, kule + rozmiar);
	return *this;
}

void Beben::Wypisz()
{
	Wypisz(rozmiar);
}

Beben::~Beben()
{
	if (kule != NULL)
	{
		delete[] kule;
		kule = NULL;
	}
	cout << "To ja DESTRUKTOR BEBNA" << endl;
}