#include "karta.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Talia 
{
private:
	Karta* lista;
	int rozmiar;

public:
	Talia();
	Talia(const Talia& t);
	Talia& Tasuj();
	Talia LosujReke(int k);
	int SumaPunktow() const;
	void Zapisz(const char* nazwa);
	~Talia();

	friend ostream& operator<<(ostream& o, const Talia& t);

};

