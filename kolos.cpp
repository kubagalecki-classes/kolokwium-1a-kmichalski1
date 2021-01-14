#include <algorithm>
#include <iostream>
#include <vector>

class Makaron
{
public:
	Makaron() = default;
	~Makaron() = default;

public:
	virtual double ileMaki(unsigned) const = 0;

	static Makaron* gotujMakaron(std::string&);
};
class Penne : public Makaron
{
public:
	Penne() = default;
	~Penne() = default;

public:
	double ileMaki(unsigned P) const override;

};

class Tagliatelle : public Makaron
{
public:
	Tagliatelle();
	Tagliatelle(double, double, double);
	~Tagliatelle();

public:
	double ileMaki(unsigned P) const override;

private:
	double L;
	double W;
	double R;

	static const double C;

};

Tagliatelle::Tagliatelle() :L(0.5), W(0.5), R(0.5)
{

}

Tagliatelle::Tagliatelle(double a, double b, double c) :L(a), W(b), R(c)
{
}

Tagliatelle::~Tagliatelle()
{
}

double Tagliatelle::ileMaki(unsigned P) const
{
	return P * L * W * (1. - R) * C;
}
const double Tagliatelle::C = 0;


template<typename T>
std::size_t polejSosem(const Tagliatelle & obj, const T & obj2) {

	return obj2.polej(obj);
}

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
template <class T>
void sortujTagiatelle(T ite, T ite2) {

	std::sort(ite, ite2);
	std::reverse(ite, ite2);
}

int main()
{
	std::vector<int> vec{ 1,2,3,8,4,2,5 };
	auto b = vec.begin();
	auto e = vec.end();

	sortujTagiatelle(b, e);

	for (auto x : vec)
		std::cout << x;
}

double Penne::ileMaki(unsigned P) const
{
	return P;
}

Makaron* Makaron::gotujMakaron(std::string& str)
{
	if (str.front() == str.back()) {
		return new Tagliatelle{ 3.14, 0.42, 0.1 };

	}
	else {
		return new Penne();
	}
}
