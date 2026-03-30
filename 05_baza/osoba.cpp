#include "osoba.h"

ostream& operator<<(ostream& stream, const Osoba& osoba)
{
    
    return stream << osoba.imie << ", " 
        << osoba.nazwisko << ", "
        << osoba.data_urodzenia << ", "
        << osoba.plec;
}

ostream& operator<<(ostream& o, const Plec plec)
{
    switch (plec) {
    
    case Plec::Kobieta:
        return o << "kobieta";
        break;
    case Plec::Mezczyzna:
        return o << "mezczyzna";
        break;
    case Plec::Nieznana:
        return o << "nieznana";
        break;
    default:
        return o << "Blad";
    }
}
