#include "gauss.h"
#include <cmath>

double Gauss::ObliczWartosc(double x) const
{
    double pi = std::acos(-1.0);

    return exp(-(x - srednia) * (x - srednia) / (2.0 * odchylenie * odchylenie)) /
        (odchylenie * sqrt(2.0 * pi));
}

ostream& operator<<(ostream& o, const Gauss& g) 
{
    return o << "Gauss (srednia=" <<  g.srednia << ", odchylenie=" << g.odchylenie << ")";
}
