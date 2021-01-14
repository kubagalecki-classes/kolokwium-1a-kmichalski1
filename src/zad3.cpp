#include "zad3.hpp"

struct Sos
{
    std::size_t polej(const Tagliatelle& t) const
    {
        return std::hash< std::string >{}(std::to_string(t.ileMaki(1)));
    }
};

TEST_CASE("Test polewania sosem", "[zad3]")
{
    const Tagliatelle t{1., 10., .2};
    auto              t_hash = std::hash< std::string >{}(std::to_string(t.ileMaki(1)));
    CHECK(t_hash == polejSosem(t, Sos{}));
}
