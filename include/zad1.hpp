#include "catch.hpp"


// Zad2
// tutaj definicja klasy Makaron
// BEZ definicji metody gotujMakaron (tylko z deklaracją)

class Makaron
{
public:
    virtual double ileMaki(unsigned P) const = 0;
    static Makaron* gotujMakaron(const std::string& str);
};

// Zad1
// tutaj definicja klasy Tagliatelle

class Tagliatelle : public Makaron
{
public:
    Tagliatelle::Tagliatelle() :L{0.5} W{0.5}, R{0.5}
    {

    }

    Tagliatelle::Tagliatelle(double a, double b, double c) :L{a}, W{b}, R{c}
    {
    }
    
    double ileMaki(unsigned P) const override
    {
        return P * L * W * (1. - R) * C;
    }

private:
    double L;
    double W;
    double R;
    
    static const double C;

};

