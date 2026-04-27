#ifndef KARTA_H
#define KARTA_H

#include <iostream>
#include <string>

using namespace std;

enum class Kolor { Kier, Karo, Pik, Trefl};
enum class Wartosc { As=1, Walet=11, Dama, Krol };

class Karta
{
private:
	Wartosc wartosc;
	Kolor kolor;
public:
	Karta();
	Karta(Wartosc wartosc, Kolor kolor);
	int Punkty() const { return (int)wartosc; }
	friend ostream& operator<<(ostream& o, const Karta& k);
};

#endif