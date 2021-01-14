#include "zad1.hpp"

#include <algorithm>
#include <iterator>
#include <deque>
#include <random>
#include <vector>

// tutaj funkcja sortujTagliatelle

template <class T>
void sortujTagiatelle(T ite, T ite2) {

    std::sort(ite, ite2);
    std::reverse(ite, ite2);
}
