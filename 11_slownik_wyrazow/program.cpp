#include "wyraz.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	/*  
	    Program testujacy klase Wyraz. Wczytuje z pliku tekstowego wyrazy, tworzy slownik (mapa) wyrazow i ich liczby wystapien, a nastepnie wypisuje zawartosc slownika.
		aaa AAA aaaa AAAA aaaa
	*/
	std::stringstream ss;      // z biblioteki <sstream>

	ss << "!@&#&*(Ala_ma++kota" << endl;

	Wyraz w;
	while (ss >> w)
	{
		cout << w << endl;
	}

	string nazwa;
	cout << "Nazwa pliku: ";
	getline(cin, nazwa);

	ifstream plik(nazwa);

	map<Wyraz, int> slownik;

	if (plik.is_open())
	{
		while (plik >> w)
		{
			// cout << w << ", ";
			// Wypelniamy slownik wyrazami z pliku
			slownik[w]++;
		}
	}
	else 
	{
		cerr << "Blad! Nie moge odczytac pliku: " << nazwa << endl;
		return 1;
	}

	// Wyswietlamy slownik
	for (auto element : slownik)
	{
		cout << element.first << " : " << element.second << endl;
	}

	return 0;
}


