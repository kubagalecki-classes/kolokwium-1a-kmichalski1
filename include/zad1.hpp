#include "catch.hpp"

// Zad2
// tutaj definicja klasy Makaron
// BEZ definicji metody gotujMakaron (tylko z deklaracją)

// Zad1
// tutaj definicja klasy Tagliatelle

#include <iostream>

class Tagliatelle
{
public:
    Tagliatelle();
    Tagliatelle(double, double, double);
    ~Tagliatelle();

public:
    double ileMaki(unsigned P) const;

private:
    double L;
    double W;
    double R;

    static const double C;

};

Tagliatelle::Tagliatelle()
{
    L = 0.5;
    W = 0.5;
    R = 0.5;
}

Tagliatelle::Tagliatelle(double a, double b, double c) :L(a), W(b), R(c)
{
}

Tagliatelle::~Tagliatelle()
{
}

double Tagliatelle::ileMaki(unsigned P) const
{
    return P * L * W *(1. - R) * C;
}
