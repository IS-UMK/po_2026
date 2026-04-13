#include "data.h"


ostream& operator<<(ostream& o, const Data& d)
{
	return o << d.dzien << "-" << d.miesiac << "-" 
		<< 	d.rok;
}