#include "zad1.hpp"

#include <vector>

// tutaj funkcja obliczMake

double obliczMake(const std::vector<Tagliatelle>& vec) {

    double M = 0;
    int licznik = 1;
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        M += vec[i].ileMaki(licznik);
        licznik++;
    }

    try {
        if (M > 100)
            throw 0;
        if (M > 50 && M <= 100)
            throw 0.0;
        if (M <= 50)
            return M;
    }
    catch(int & e){

    }
    catch (double& e) {

    }
}
