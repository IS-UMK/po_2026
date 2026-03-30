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

	Baza baza;

	cout << baza;

	baza.Dodaj(o2);
	cout << baza;

	for (int i = 0; i < 101; i++)
	{
		baza.Dodaj(o2);
	}
	cout << baza;






}


