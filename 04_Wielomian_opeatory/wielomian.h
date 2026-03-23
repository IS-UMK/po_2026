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
    Wielomian(double x) :Wielomian(0) { wsp[0] = x; }

    Wielomian Pochodna(int ktora = 1);

    void Wypisz();
    ~Wielomian();
    Wielomian& operator=(const Wielomian& w);
    double& operator[](int i);
    friend Wielomian Dodaj(const Wielomian& a, const Wielomian& b);
    friend ostream& operator<<(ostream& o, const Wielomian& w);
    friend Wielomian operator+(const Wielomian& a, const Wielomian& b);
};


ostream& operator<<(ostream& o, const Wielomian& w);

Wielomian Dodaj(const Wielomian& a, const Wielomian& b);
Wielomian operator+(const Wielomian& a, const Wielomian& b);

