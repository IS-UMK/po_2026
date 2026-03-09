#include "Beben.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	Beben beben(49);
	
	/*
	beben.Wypelnij();
	beben.Mieszaj();
	beben.Wypisz(6);
	beben.Wypisz();
	*/

	beben.Wypelnij().Mieszaj().Wypisz(6);

	// beben.~Beben();
	
}