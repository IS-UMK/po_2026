#include "wielomian.h"
#include "parabola.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	Parabola  p0;
	Parabola  p1(1, -1e6, 1);
	Parabola2 p2(1, -1e6, 1);

	cout << "Parabola domyslna " << p0 << endl;
	cout << "Parabola p1 " << p1 << endl;
	cout << "Ekstremum p1 = " << p1.Ekstremum() << endl;
	p1.Wypisz();
	cout << endl;
	((Wielomian)p1).Wypisz();
	cout << endl;

	double x1, x2;
	int k = p1.Pierwiastki(&x1, &x2);
	cout << "Liczba miejsc zerowych " << k << endl;
	if (k > 0)
	{
		cout << "x1= " << fixed << setprecision(15) << x1 << endl;
		cout << "x2= " << fixed << setprecision(15) << x2 << endl;
	}
	cout << "f(x1)=" << fixed << setprecision(15) << p1.ObliczWartosc(x1) << endl;
	cout << "f(x2)=" << fixed << setprecision(15) << p1.ObliczWartosc(x2) << endl;

	cout << "\nZ uzyciem wzorow Vietea" << endl;
	k = p2.Pierwiastki(&x1, &x2);
	cout << "Liczba miejsc zerowych " << k << endl;
	if (k > 0)
	{
		cout << "x1= " << fixed << setprecision(15) << x1 << endl;
		cout << "x2= " << fixed << setprecision(15) << x2 << endl;
	}
	cout << "f(x1)=" << fixed << setprecision(15) << p2.ObliczWartosc(x1) << endl;
	cout << "f(x2)=" << fixed << setprecision(15) << p2.ObliczWartosc(x2) << endl;

	



	
}