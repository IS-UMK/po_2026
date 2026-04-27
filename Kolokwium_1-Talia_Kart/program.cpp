#include "karta.h"
#include "talia.h"
#include <iostream>

using namespace std;

int main()
{
	Karta karta0;
	cout << karta0 << endl;
	Karta karta1((Wartosc)2, Kolor::Karo);
	cout << karta1 << endl;

	Talia talia;
	cout << talia;

	cout << "Suma punktow: " << talia.SumaPunktow() << endl;
	talia.Tasuj();
	cout << "Po tasowaniu" << endl;
	cout << talia;

	cout << "Reka 10 kart" << endl;
	cout << "Ile kart losowac: ";
	int k;
	cin >> k;
	Talia reka = talia.LosujReke(k);
	cout << reka;
	cout << "Suma punktow reki: " << reka.SumaPunktow() << endl;

	reka.Zapisz("wynik.txt");

}