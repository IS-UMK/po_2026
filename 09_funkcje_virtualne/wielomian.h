#include <iostream>
#include <iomanip>
#include "funkcja.h"

#ifndef WIELOMIAN_H
#define WIELOMIAN_H

using namespace std;

class Wielomian : public Funkcja
{
protected:
    int st;
    double* wsp;

    Wielomian(int st);

public:
    Wielomian();
    Wielomian(int st, const double* wsp);
    Wielomian(const Wielomian&);
    Wielomian(double x) :Wielomian(0) { wsp[0] = x; }

    Wielomian Pochodna(int ktora = 1);

    virtual double ObliczWartosc(double x) const override;

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

#endif