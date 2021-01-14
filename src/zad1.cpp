#include "zad1.hpp"

const double Tagliatelle::C{1.};

TEST_CASE("Test klasy Tagliatelle", "[zad1]")
{
    const Tagliatelle domyslnie_skonstruowany{};
    CHECK(domyslnie_skonstruowany.ileMaki(10) == Approx(10. * .5 * .5 * .5));

    const Tagliatelle t{.2, .3, .4};
    CHECK(t.ileMaki(10) == Approx(10. * .2 * .3 * .6));
}
