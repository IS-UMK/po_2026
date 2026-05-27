#include "wektor.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	Wektor<int> wektor1;
	cout << "Pusty wektor<int> ma rozmiar " << wektor1.Rozmiar() << endl;
	cout << wektor1 << endl << endl;

	// dodajemy 100 elementow
	for (int i = 0; i < 100; i++)
	{
		wektor1.Dodaj(i);
	}

	cout << "Po dodaniu 100 elementow:" << endl;
	cout << wektor1 << endl;

	// modyfikujemy 5 element
	wektor1[5] = 42;

	cout << "Po modyfikacji 5 elementu:" << endl;
	cout << wektor1 << endl;

	Wektor<float> wektor2(100);
	cout << "wektor<float> wektor2 ma rozmiar " << wektor2.Rozmiar() << endl;
	cout << wektor2 << endl << endl;

	Wektor<string> wektor3;

	string nazwa_pliku;

	cout << "Podaj nazwe pliku: ";
	getline(cin, nazwa_pliku);

	string linia;
	ifstream myfile(nazwa_pliku);
	if (myfile.is_open())
	{
		while (getline(myfile, linia))
			wektor3.Dodaj(linia);
		myfile.close();
	}
	else
	{
		cerr << "Blad czytania pliku: " << nazwa_pliku << endl;
		return 1;
	}

	cout << "Zawartosc pliku z odwróconą kolejnością linii:" << endl;
	for (int i = wektor3.IleElementow() - 1; i >= 0; i--)
	{
		cout << i << " : " << wektor3[i] << endl;
	}

}