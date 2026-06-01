#ifndef WYRAZ_H
#define WYRAX_H

#include<vector>
#include<iostream>
#include<cctype>

using namespace std;

class Wyraz
{
private:
	vector<char> wyraz;

public:
	Wyraz();
	Wyraz(const Wyraz&);

	friend ostream& operator<<(ostream& o, const Wyraz& w);
	friend istream& operator>>(istream& o, Wyraz& w);

	bool operator<(const Wyraz& w) const;
	int Dlugosc() const { return wyraz.size(); }

};



#endif