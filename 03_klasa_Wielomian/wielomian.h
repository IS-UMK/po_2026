#include <iostream>
#include <iomanip>

using namespace std;

class Wielomian
{
private:
    int st;
    double* wsp;

    Wielomian(int st);

public:
    Wielomian();
    Wielomian(int st, const double* wsp);
    Wielomian(const Wielomian&);

    Wielomian Pochodna(int ktora = 1);

    void Wypisz();
    ~Wielomian();

    friend Wielomian Dodaj(const Wielomian& a, const Wielomian& b);

};


Wielomian Dodaj(const Wielomian& a, const Wielomian& b);

