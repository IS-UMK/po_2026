#include "data.h"
#include "osoba.h"
#include <iostream>
#include "baza.h"

using namespace std;

int main()
{
	Data d1;
	Data d2(30, 3, 2026);

	cout << "Data domyslna " << d1 << endl;
	cout << "Data dzisieksza " << d2 << endl;

	Osoba o1;
	Osoba o2("Marek", "Grochowski", Data(1, 1, 1999), Plec::Mezczyzna);

	cout << "Osoba domyslna " << o1 << endl;
	cout << "Osoba 2  " << o2 << endl;


	// Osoba osoba3 = Osoba::WczytajOsobe();
	
	// bool wynik = osoba3 < o2;
	// cout << "Wynik " << wynik << endl;
	Baza baza;
	cout << baza;

	baza.Dodaj(o2);

	Osoba o3("Julia", "Zzzzzz", Data(1, 1, 1999), Plec::Kobieta);
	baza.Dodaj(o3);

	Osoba o4("Adam", "Nowak", Data(1, 1, 1999), Plec::Mezczyzna);
	baza.Dodaj(o4);
	Osoba o5("Marek", "Arciszewski", Data(1, 1, 1999), Plec::Mezczyzna);
	baza.Dodaj(o5);

	cout << baza;

	cout << "Po posortowaniu" << endl;

	baza.Sortuj();
	cout << baza;

	baza.Zapisz("baza.txt");



	/*
	for (int i = 0; i < 101; i++)
	{
		baza.Dodaj(osoba3);
	}
	cout << baza;

	*/




}


