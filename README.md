# Kolokwium I - Makarony
_Czas pracy: 90 minut_

## Zadanie 1
Napisz klasę `Tagliatelle`, która posiada:
- prywatne pole `double L`, reprezentujące długość kawałka makaronu
- prywatne pole `double W`, reprezentujące szerokość kawałka makaronu
- prywatne pole `double R`, reprezentujące proporcję jajek do mąki
- prywatne statyczne pole `const double C`, reprezentujące pewną stałą. Nie definiuj jego wartości, a jedynie je zadeklaruj (definicja znajdzie się w kodzie z testami).
- publiczny konstruktor parametryczny `Tagliatelle(double, double, double)`, nadający polom odpowiednie wartości przy pomocy listy inicjalizacyjnej
- publiczny konstruktor domyślny nadający wszystkim trzem polom wartość `0.5`.
- publiczną metodę `double ileMaki(unsigned P) const` zwracającą masę mąki potrzebną do przygotowania liczby porcji równej argumentowi metody, zgodnie ze wzrorem `P * L * W * (1. - R) * C`

## Zadanie 2
Napisz klasę `Makaron`, która posiada publiczną, czysto wirtualną (abstrakcyjną) metodę `double ileMaki(unsigned) const`. Zmodyfikuj `Tagliatelle` tak, aby klasa ta dziedziczyła publicznie po `Makaron` i nadpisywała odpowiednią metodę. Następnie napisz klasę `Penne`, która także dziedziczy publicznie po `Makaron` oraz nadpisuje `ileMaki` tak, aby metoda ta zwracała po prostu podaną wartość (skonwertowaną na typ `double`). Dodaj do klasy `Makaron` publiczną statyczną metodę `gotujMakaron`, która:
- przyjmuje przez stałą referencję jeden argument typu `std::string`
- zwraca wskaźnik do obiektu typu `Makaron`
- jeżeli pierwszy i ostatni znak argumentu są takie same, dynamicznie alokuje pod zwracanym adresem obiekt typu `Tagliatelle` z polami o wartościach `L == 3.14`, `W == 0.42`, `R == 0.1`
- jeżeli pierwszy i ostatni znak argumentu są inne, dynamicznie alokuje pod zwracanym adresem obiekt typu `Penne` (użyj wygenerowanego przez kompilator konstruktora domyślnego).

Na koniec dokonaj modyfikacji klasy `Makaron` potrzebnej do poprawnego usuwania obiektów klas `Tagliatelle` i `Penne` przez wskaźnik na obiekt `Makaron`.

**Podpowiedź:** Klasa `std::string` posiada metody `front` i `back`, służące do dostępu do odpowiednio pierwszego i ostatniego znaku.

## Zadanie 3
Napisz szablon funkcji `polejSosem`, który:
- sparametryzowany jest jednym typem
- przyjmuje jako pierwszy argument stałą referencję do obiektu typu `Tagliatelle`
- przyjmuje jako drugi argument stałą referencję do obiektu typu, którym jest sparametryzowany (obiekt ten reprezentuje sos)
- zwraca obiekt typu `std::size_t`, będący wynikiem wywołania metody `polej` drugiego argumentu na pierwszym argumencie (załóż, że typ będący parametrem szablonu posiada taką metodę)

## Zadanie 4
Napisz funkcję `obliczMake`, która:
- przyjmuje przez stałą referencję wektor (w znaczeniu `std::vector`) obiektów typu `Tagliatelle`
- oblicza `M` - sumaryczną ilość mąki, potrzebną na przygotowanie 1 porcji ostatniego elementu wektora, 2 porcji przedostatniego elementu wektora, 3 porcji trzeciego elementu od końca, itd. (użyj metody `ileMaki`)
- jeżeli `M` jest większe niż 100, rzuca wyjątkiem typu `int` o dowolnej wartości.
- jeżeli `M` jest większe niż 50 i mniejsze lub równe 100 rzuca wyjątkiem typu `double` o dowolnej wartości
- jeżeli `M` jest mniejsze lub równe 50 zwraca `M`

## Zadanie 5
Napisz algorytm (szablon funkcji) `sortujTagliatelle`, który:
- przyjmuje 2 argumenty typu, którym jest sparametryzowany - iteratory do początku i za koniec zakresu obiektów typu `Tagliatelle`
- sortuje elementy zakresu zgodnie z malejącą wartością zwracaną przez metodę `ileMaki`
