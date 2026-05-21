#include "funkcja.h"
#include "parabola.h"
#include "gauss.h"
#include "wielomian.h"

#include <iostream>
using namespace std;

/* Obliczanie calki funkcji f na przedziale [a, b] metoda prostokatow 
   Argumenty:
   f - wskaznik na funkcje, ktorej calke chcemy obliczyc
   a - poczatek przedzialu calkowania
   b - koniec przedzialu calkowania
   n - liczba wezlow calkowania (im wiecej, tym dokladniejsza calka, ale tez dluzej sie liczy)
   Zwraca:
   Wartosc calki funkcji f na przedziale [a, b]
*/

double calka(Funkcja* f, double a, double b, int n=100)
{
	double h = (b - a) / n;
	double wynik = 0.0;
	
	for (int i = 0; i <= n; ++i)
	{
		wynik += f->ObliczWartosc(a + i * h);
	}
	return wynik * h;
}


int main()
{
	int n;

	cout << "Ile wezlow calkowania? " ;
	cin >> n;

	// calkowanie funkcji gaussa na przedziale [srednia, 3*odchylenie]
	double srednia = 3, odchylenie = 5;
	Gauss g(srednia, odchylenie);
	
	double a = srednia, b = 3.0 * odchylenie;

	double wynik = calka(&g, a, b, n);

	cout << "Funkcja: " << g << endl;
	cout << "Przedzial calkowania: [" << a << ", " << b << "]" << endl; 
	cout << "Wynik calkowania = " << wynik << endl << endl;

	// calkowanie funkcji paraboli na przedziale [0, 1]
	Parabola p(1, 0, 0);
	
	a = 0.0, b = 1.0;
	wynik = calka(&p, a, b, n);
	
	cout << "Funkcja: " << p << endl;
	cout << "Przedzial calkowania: [" << a << ", " << b << "]" << endl; 
	cout << "Wynik calkowania = " << wynik << endl;
	
	return 0;
}