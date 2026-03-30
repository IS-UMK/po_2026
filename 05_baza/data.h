#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data
{
private:
	int dzien;
	int miesiac;
	int rok;
public:
	Data(int dzien, int miesiac, int rok) :
		dzien{ dzien }, miesiac{ miesiac }, rok{ rok }
	{
	}
	Data() :Data(1, 1, 1970) {}

	friend ostream& operator<<(ostream& o, const Data& d);
};
ostream& operator<<(ostream& o, const Data& d);
#endif