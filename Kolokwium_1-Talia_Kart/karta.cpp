#include "karta.h"

Karta::Karta()
{
	wartosc = Wartosc::As;
	kolor = Kolor::Kier;
}

Karta::Karta(Wartosc w, Kolor k)
{
	this->wartosc = w;
	this->kolor = k;
}

string KolorNaString(Kolor kolor)
{
	string wynik;
	switch (kolor)
	{
	case Kolor::Trefl:
		wynik= "Trefl";
		break;
	case Kolor::Karo:
		wynik = "Karo";
		break;
	case Kolor::Pik:
		wynik = "Pik";
		break;
	case Kolor::Kier:
		wynik = "Kier";
		break;
	}
	return wynik;
}

string WartoscNaString(Wartosc wartosc)
{
	string wynik;
	switch (wartosc)
	{
	case Wartosc::Krol:
		wynik = "Krol";
		break;
	case Wartosc::As:
		wynik = "As";
		break;
	case Wartosc::Walet:
		wynik = "Walet";
		break;
	case Wartosc::Dama:
		wynik = "Dama";
		break;
	default:
		wynik = to_string((int)wartosc);
	}
	return wynik;
}

ostream& operator<<(ostream& o, const Karta& k)
{
	o << WartoscNaString(k.wartosc) << " "
		<< KolorNaString(k.kolor);
	return o;
}


