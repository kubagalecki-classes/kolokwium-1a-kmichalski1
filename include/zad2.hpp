#include "zad1.hpp"

#include <memory>
#include <string>
#include <type_traits>

#include <iostream>

// tutaj klasa Penne

class Penne : public Makaron
{

public:
   double Penne::ileMaki(unsigned P) const override
{
    return (double)P;
}

};


// tutaj definicja metody gotujMakaron

Makaron* Makaron::gotujMakaron(std::string& str)
{
    if (str.front() == str.back()) {
        return new Tagliatelle(3.14, 0.42, 0.1);

    }
    else {
        return new Penne();
    }
}
