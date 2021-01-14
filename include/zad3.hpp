#include "zad1.hpp"
#include <cstdint>
#include <functional>

// tutaj funkcja polejSosem

template<typename T>
std::size_t polejSosem(const Tagliatelle & obj, const T & obj2) {

    return obj2.polej(obj);
}
