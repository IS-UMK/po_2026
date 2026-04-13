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


Osoba Osoba::WczytajOsobe()
{
    cout << "Podaj imie: ";
    string imie;
    cin >> imie;
    cout << "Podaj nazwisko: ";
    string nazwisko;
    cin >> nazwisko;
    cout << "Podaj date (dzien miesiac rok): ";
    int dzien, miesiac, rok;
    cin >> dzien >> miesiac >> rok;
    cout << "Podaj plec (0 - Kobieta, 1 - Mezczyzna)";
    int plec;
    cin >> plec;

    return Osoba(imie, nazwisko, Data(dzien, miesiac, rok), (Plec)plec);
}

bool Osoba::operator<(const Osoba& o) const
{
    return this->nazwisko < o.nazwisko;
}
