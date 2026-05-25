#ifndef WEKTOR_H
#define WEKTOR_H

#include<iostream>
using namespace std;


template <typename T>
class Wektor;

template <typename T>
ostream& operator<< (ostream& o, const Wektor<T>& w);

const int rozmiar_wektora = 10;

template <typename T>
class Wektor
{
private:
	int rozmiar;
	int liczba_elementow;
	T *elementy;

public:

	Wektor(int rozmiar = rozmiar_wektora) :elementy{ new T[rozmiar] },
		rozmiar{ rozmiar }, liczba_elementow{ 0 } { }

	int Rozmiar() const { return rozmiar;  }
	int IleElementow() const { return liczba_elementow; }
	void Dodaj(const T& element);

	T& operator[](int i) { return elementy[i]; }
	void Usun() { if (liczba_elementow > 0) liczba_elementow--; }
	void Wyczysc() { liczba_elementow = 0; }

	friend ostream& operator<< < >  (ostream& o, const Wektor<T>& w);

	~Wektor() {
		if (elementy != nullptr)
		{
			delete[] elementy;
			elementy = nullptr;
		}
	}

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
	o << "Ile elementow: " << w.IleElementow() << endl;
	o << "Elementy: ";
	for (int i = 0; i < w.IleElementow(); i++)
	{
		o << w.elementy[i] << ", ";
	}
	return o;
}


#endif


