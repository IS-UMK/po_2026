#include<string>
#include<iostream>

using namespace std;

class Beben
{
private:
	int rozmiar;
	int* kule;
	string opis;

public:
	Beben(int n);
	Beben& Wypelnij();
	Beben& Mieszaj();
	void Wypisz(int k);
	void Wypisz();
	~Beben();
};

