#include "zad4.hpp"

TEST_CASE("Test obliczania maki", "[zad4]")
{
    CHECK(obliczMake({}) == Approx(0.));
    CHECK(obliczMake({{1., 1., 0.}, {1., 1., 0.}}) == Approx(3.));
    CHECK_THROWS_AS(obliczMake({{10., 10., 0.}, {10., 10., 0.}}), int);
    CHECK_THROWS_AS(obliczMake({{10., 9.9, .5}, {.4, 1., 0.}}), double);
}
