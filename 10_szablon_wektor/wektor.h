#ifndef WEKTOR_H
#define WEKTOR_H

#include<iostream>
using namespace std;

// deklaracja wyprzedzajaca na potrzeby szablonu zaprzyjaznionego operatora <<
template <typename T>
class Wektor;

template <typename T>
ostream& operator<< (ostream& o, const Wektor<T>& w);

const int domyslny_rozmiar = 10;

template <typename T>
class Wektor
{
private:
	int rozmiar;
	int liczba_elementow;
	T *elementy;

public:

	Wektor(int rozmiar = domyslny_rozmiar) :elementy{ new T[rozmiar] },
		rozmiar{ rozmiar }, liczba_elementow{ 0 } { }

	int Rozmiar() const { return rozmiar;  }
	int IleElementow() const { return liczba_elementow; }
	void Dodaj(const T& element);

	T& operator[](int i) { return elementy[i]; }
	void Usun() { if (liczba_elementow > 0) liczba_elementow--; }
	void Wyczysc() { liczba_elementow = 0; }

	friend ostream& operator<< < >  (ostream& o, const Wektor<T>& w);

	~Wektor(); 

	Wektor(const Wektor<T>& w);
	Wektor<T>& operator=(const Wektor<T>& t);

};

template <typename T> 
void Wektor<T>::Dodaj(const T& element)
{
	if (rozmiar == liczba_elementow)
	{
		int nowy_rozmiar = 2 * rozmiar;
		T* nowe_elementy = new T[nowy_rozmiar];

		for (int i = 0; i < liczba_elementow; i++)
		{
			nowe_elementy[i] = elementy[i];
		}
		delete[] elementy;
		elementy = nowe_elementy;
		rozmiar = nowy_rozmiar;
	}

	elementy[liczba_elementow] = element;
	liczba_elementow++;
}

template <typename T>
ostream& operator<<(ostream& o, const Wektor<T>& w)
{
	o << "Rozmiar: " << w.Rozmiar() << endl;
	o << "Liczba elementow: " << w.IleElementow() << endl;
	o << "Elementy: ";
	for (int i = 0; i < w.IleElementow(); i++)
	{
		o << w.elementy[i] << ", ";
	}
	return o;
}

template <typename T>
Wektor<T>::~Wektor()
{
	if (elementy != nullptr)
	{
		delete [] elementy;
		elementy = nullptr;
	}
	liczba_elementow = 0;
	rozmiar = 0;
}

template <typename T>
Wektor<T>::Wektor(const Wektor<T>& w):Wektor(w.rozmiar)
{
	liczba_elementow = w.liczba_elementow;
	for (int i = 0; i < liczba_elementow; i++)
	{
		elementy[i] = w.elementy[i];
	}
}

template <typename T>
Wektor<T>& Wektor<T>::operator=(const Wektor<T>& w)
{
	if (rozmiar < w.liczba_elementow)
	{
		rozmiar = w.rozmiar;
		delete[] elementy;
		elementy = new T[rozmiar];
	}
	liczba_elementow = w.liczba_elementow;
	for (int i = 0; i < w.liczba_elementow; i++)
		elementy[i] = w.elementy[i];
	
	return  *this;
}

#endif


