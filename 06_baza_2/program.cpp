#include "data.h"
#include "osoba.h"
#include <iostream>
#include "baza.h"

using namespace std;

int main()
{
	// Test klasy Data
	Data data1;
	Data data2(30, 3, 2026);

	cout << "Data domyslna " << data1 << endl;
	cout << "Data dzisiejsza " << data2 << endl;

	// Test klasy Osoba
	Osoba osoba1;
	Osoba osoba2("Marek", "Grochowski", Data(1, 1, 1999), Plec::Mezczyzna);

	cout << "Osoba 1 (domyslna) " << osoba1 << endl;
	cout << "Osoba 2  " << osoba2 << endl;

	// Test wczytywania osoby z klawiatury
	Osoba osoba3 = Osoba::WczytajOsobe();
	cout << "Wczytana osoba 3: " << osoba3 << endl;

	// Test operatora < dla sortowania
	bool wynik = osoba2 < osoba3;
	cout << "Czy osoba 2 < osoba 3 ? " << wynik << endl;

	cout << "Czy osoba 3 < osoba 2 ? " << (osoba3 < osoba2) << endl;
	
	Baza baza;
	baza.Dodaj(osoba2);
	baza.Dodaj(osoba3);
	

	Osoba osoba4("Julia", "Zielinska", Data(13, 11, 1999), Plec::Kobieta);
	baza.Dodaj(osoba4);

	baza.Dodaj(Osoba("Adam", "Nowak", Data(1, 1, 1999), Plec::Mezczyzna));
	baza.Dodaj(Osoba("Marek", "Arciszewski", Data(1, 1, 1999), Plec::Mezczyzna));
	cout << baza;

	cout << "\nPo posortowaniu" << endl << endl;

	baza.Sortuj();
	cout << baza;

	// Zapis bazy danych do pliku
	baza.Zapisz("baza.txt");
}