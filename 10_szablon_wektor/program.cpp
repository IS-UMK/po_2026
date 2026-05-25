#include "wektor.h"
#include <iostream>
#include<string>
#include <fstream>

using namespace std;

int main()
{
	Wektor<int> wektor1;
	cout << "Rozmiar w1 = " << wektor1.Rozmiar() << endl;

	for (int i = 0; i < 100; i++)
	{
		wektor1.Dodaj(i);
	}
	cout << wektor1 << endl;;

	wektor1[5] = 42;

	cout << wektor1 << endl;;






	Wektor<float> wektor2(100);
	cout << "Rozmiar w2 = " << wektor2.Rozmiar() << endl;

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

	for (int i = wektor3.IleElementow(); i >=0 ; i--)
	{
		cout << i << " : " << wektor3[i] << endl;
	}

}