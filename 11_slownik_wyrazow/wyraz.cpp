#include "wyraz.h"


Wyraz::Wyraz()
{

}

Wyraz::Wyraz(const Wyraz& w)
{
	wyraz.clear();
	for(auto znak:w.wyraz)
	{
		wyraz.push_back(znak);
	}
}

bool Wyraz::operator<(const Wyraz& w) const
{
	int min_dl = (this->Dlugosc() < w.Dlugosc()) ?
		this->Dlugosc() : w.Dlugosc();

	for (int i = 0; i < min_dl; i++)
	{
		if (tolower(wyraz[i]) != tolower(w.wyraz[i]))
			return tolower(wyraz[i]) < tolower(w.wyraz[i]);
	}
	return Dlugosc() < w.Dlugosc();
}


istream& operator>>(istream& in, Wyraz& w)
{
	w.wyraz.clear();

	int znak;
	while (in.good() && (znak = in.get()) && !isalpha(znak)) { };

	if (!in.good()) return in; 

	w.wyraz.push_back(znak);

	while (in.good() && (znak = in.get()) && isalpha(znak))
	{
		w.wyraz.push_back(znak);
	};
	return in;
}

ostream& operator<<(ostream& o, const Wyraz& w)
{
	for (auto znak : w.wyraz)
		o.put(tolower(znak));
	return o;
}

