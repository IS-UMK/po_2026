#include "wielomian.h"

int main()
{
	Wielomian w1;

	cout << "Wielomian domyslny: ";
	w1.Wypisz();
	cout << endl;

	cout << "Wielomian << " << w1 << endl;

	double wsp[] = { 1.0, -2.0, 3.0 };

	Wielomian w2(2, wsp);
	cout << "Wielomian w2: ";
	w2.Wypisz();
	cout << endl;

	Wielomian w3(w2);
	cout << "Wielomian w3: ";
	w3.Wypisz();
	cout << endl;

	Wielomian w4 = w2;  // tu zadziała konstruktor kopiujący
	cout << "Wielomian w4: ";
	w4.Wypisz();
	cout << endl;

	//Wielomian w5 = Dodaj(w4, w2);
	Wielomian w5 = w4 + w2;     // operator + jako funkcja zaprzyjaźniona
	cout << "Suma w4 + w2: ";
	w5.Wypisz();
	cout << endl;


	Wielomian w6(1, wsp);
	cout << "w6: ";            // operator << jako funkcja zaprzyjaźniona
	w6.Wypisz();
	cout << endl;

	Wielomian w7 = Dodaj(w5, w6);
	cout << "Suma w5 + w6: ";
	w7.Wypisz();
	cout << endl;

	w1 = w2 = w3 = w4;   // operator = dla Wielomianów

	cout << "Po instrukcji w1 = w2 = w3 = w4" << endl <<
		"w1 " << w1 << endl <<
		"w2 " << w2 << endl <<
		"w3 " << w3 << endl <<
		"w4 " << w4 << endl;

	w4[0] = 42;    // operator [] dla Wielomianów
	cout << "w4 " << w4 << endl;
	w4[0]++;
	cout << "w4 " << w4 << endl;

	Wielomian w8 = 3.14;     // konstruktor konwertujący z double na Wielomian
	cout << "w8 " << w8 << endl;

	cout << w4 + 3.14 << endl;   // tu zadziała konstruktor konwertujący z double na Wielomian, a potem operator + dla Wielomianów

}