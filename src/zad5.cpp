#include "zad5.hpp"

Tagliatelle randomNoodle()
{
    static std::mt19937                             prng{std::random_device{}()};
    static std::uniform_real_distribution< double > dist{0., 1.};
    return Tagliatelle{dist(prng), dist(prng), dist(prng)};
}

template < typename It >
bool checkSorted(It b, It e)
{
    std::vector< double > v(std::distance(b, e));
    std::transform(b, e, v.begin(), [](const Tagliatelle& t) { return t.ileMaki(1); });
    std::reverse(v.begin(), v.end());
    return std::is_sorted(v.cbegin(), v.cend());
}

TEST_CASE("Test sortowania Tagliatelle", "[zad5]")
{
    constexpr auto size = 20;

    std::vector< Tagliatelle > v;
    v.reserve(size);
    std::generate_n(std::back_inserter(v), size, randomNoodle);
    sortujTagliatelle(v.begin(), v.end());
    CHECK(checkSorted(v.cbegin(), v.cend()));

    std::deque< Tagliatelle > d;
    std::generate_n(std::back_inserter(d), size, randomNoodle);
    sortujTagliatelle(d.begin(), d.end());
    CHECK(checkSorted(d.cbegin(), d.cend()));
}
