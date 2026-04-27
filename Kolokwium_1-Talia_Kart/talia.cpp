#include "talia.h"

Talia::Talia()
{
	rozmiar = 52;
	lista = new Karta[rozmiar];

	int i = 0;
	for (int w = 1; w <= 13; w++)
	{
		for (int k = 0; k < 4; k++)
		{
			lista[i] = Karta((Wartosc)w, (Kolor)k);
			i++;
		}
	}
}

Talia::Talia(const Talia& t)
{
	lista = new Karta[t.rozmiar];
	rozmiar = t.rozmiar;

	for (int i = 0; i < rozmiar; i++)
	{
		lista[i] = t.lista[i];
	}
}

Talia::~Talia()
{
	if (lista != nullptr)
	{
		delete[] lista;
		lista = nullptr;
	}
}

ostream& operator<<(ostream& o, const Talia& t)
{
	for (int i = 0; i < t.rozmiar; i++)
	{
		o << i + 1 << ": " << t.lista[i] << endl;
	}
	return o;
}

int Talia::SumaPunktow() const
{
	int suma = 0;
	for (int i = 0; i < rozmiar; i++)
		suma = suma + lista[i].Punkty();
	return suma;
}


Talia& Talia::Tasuj()
{
	for (int i = 0; i < rozmiar; i++)
	{
		int k = rand() % rozmiar;
		Karta tmp = lista[i];
		lista[i] = lista[k];
		lista[k] = tmp;
	}
	return *this;
}


Talia Talia::LosujReke(int k)
{
	Talia nowa_talia;

	nowa_talia.rozmiar = k;
	delete[] nowa_talia.lista;
	nowa_talia.lista = new Karta[k];

	for (int i = 0; i < k; i++)
	{
		nowa_talia.lista[i] = lista[i];
	}
	return nowa_talia;
}

void Talia::Zapisz(const char* nazwa)
{
	ofstream plik(nazwa);
	if (plik.is_open())
	{
		plik << *this;
		plik.close();
	}
}
