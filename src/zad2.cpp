#include "zad2.hpp"

TEST_CASE("Test polimorfizmu", "[zad2]")
{
    Makaron* m_ptr1 = Makaron::gotujMakaron("aa");
    REQUIRE(dynamic_cast< Tagliatelle* >(m_ptr1));
    CHECK(m_ptr1->ileMaki(10) == Approx(10 * 3.14 * .42 * .9));
    delete m_ptr1;

    auto m_ptr2 = Makaron::gotujMakaron("ab");
    REQUIRE(dynamic_cast< Penne* >(m_ptr2));
    CHECK(m_ptr2->ileMaki(10) == Approx(10.));
    delete m_ptr2;
}