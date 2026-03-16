#include "wielomian.h"

int main()
{
	Wielomian w1;

	cout << "Wielomian domyslny: ";
	w1.Wypisz();
	cout << endl;

	
	double wsp[] = { 1.0, -2.0, 3.0 };

	Wielomian w2(2, wsp);
	cout << "Wielomian w2: ";
	w2.Wypisz();
	cout << endl;

	Wielomian w3(w2);
	cout << "Wielomian w3: ";
	w3.Wypisz();
	cout << endl;

	Wielomian w4 = w2;
	cout << "Wielomian w4: ";
	w4.Wypisz();
	cout << endl;

	Wielomian w5 = Dodaj(w4, w2);
	cout << "Suma w4 + w2: ";
	w5.Wypisz();
	cout << endl;

	Wielomian w6(1, wsp);
	cout << "w6: ";
	w6.Wypisz();
	cout << endl;

	int x = 1 + 5;
	Wielomian w7 = Dodaj(w5, w6);
	cout << "Suma w5 + w6: ";
	w7.Wypisz();
	cout << endl;
}