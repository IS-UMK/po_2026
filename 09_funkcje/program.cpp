#include "wielomian.h"
#include "parabola.h"
#include <iomanip>
#include <iostream>
#include "gauss.h"
#include "funkcja.h"

using namespace std;


double calka(Funkcja* f, double a, double b, int n)
{
	double h = (b - a) / n;
	double wynik = 0.0;
	for (double x = a; x <= b; x += h)
	{
		wynik += f->ObliczWartosc(x);
	}
	return wynik * h;
}



int main()
{

	Gauss g1;

	cout << "g1 " << g1 << endl;

	double x = 1;
	cout << "g1(x) = " << g1.ObliczWartosc(x) << endl;


	Gauss g2(1, 2);

	cout << "g2 " << g2 << endl;
	cout << "g2(x) = " << g2.ObliczWartosc(x) << endl;
	for (x = -10; x < +10; x++)
	{
		cout << x << " : " << g2.ObliczWartosc(x) << endl;
	}

	Funkcja *jakas_funkcja;

	jakas_funkcja = &g2;

	cout << "wartosc funkcji " << jakas_funkcja->ObliczWartosc(1) << endl;

	double wsp[] = { 1, 1, 1 };
	Wielomian w1(2,wsp );

	jakas_funkcja = &w1;
	cout << "wartosc funkcji " << jakas_funkcja->ObliczWartosc(1) << endl;

	double sr = 3;
	double odch = 5;
	Gauss g3(sr, odch);

	double wynik = calka(&g3, sr, sr + 3 * odch, 1000);

	cout << "Calka " << g3 << " wynosi " << wynik << endl;

	Parabola p(1, 0, 0);
	wynik = calka(&p, 0, 1, 1000);
	cout << "Calka " << p << " na[0, 1] wynosi " << wynik << endl;
	
}