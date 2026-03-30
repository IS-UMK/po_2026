#ifndef OSOBA_H
#define OSOBA_H

#include<string>
#include<iostream>
#include "data.h"

using namespace std;

enum class Plec {
	Kobieta, 
	Mezczyzna, 
	Nieznana
};

ostream& operator<<(ostream& o, const Plec plec);

class Osoba
{
private:
	string imie;
	string nazwisko;
	Data data_urodzenia;
	Plec plec;
public:
	Osoba(const string& imie, const string& nazwisko, Data data,
		Plec plec) :imie{ imie }, nazwisko{ nazwisko },
		data_urodzenia{ data }, plec{ plec } { 	}

	Osoba(const char* imie="", const char* nazwisko="", 
		Data data = Data(), Plec plec = Plec::Nieznana):imie{ imie }, 
		nazwisko{ nazwisko }, data_urodzenia{ data }, 
		plec{ plec } { }

	friend ostream& operator<<(ostream& stream, const Osoba& osoba);

};


#endif