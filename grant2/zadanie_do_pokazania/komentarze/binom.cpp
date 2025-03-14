#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Dwa z najczesciej uzywanych typow o dlugich nazwach - ich skrocenie jest bardzo istotne
typedef vector<int> VI;
typedef long long LL;

// W programach bardzo rzadko mozna znalezc w pelni zapisana instrukcje petli. Zamiast niej, wykorzystywane sa trzy nastepujace makra:
// FOR - petla zwiekszajaca zmienna x od b do e wlacznie
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
// FORD - petla zmniejszajaca zmienna x od b do e wlacznie
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
// REP - petla zwiekszajaca zmienna x od 0 do n. Jest ona bardzo czesto wykorzystywana do konstruowania i przegladania struktur danych
#define REP(x, n) for(int x = 0; x < (n); ++x)
// Makro VAR(v,n) deklaruje nowa zmienna o nazwie v oraz typie i wartosci zmiennej n. Jest ono czesto wykorzystywane podczas operowania na iteratorach struktur danych z biblioteki STL, ktorych nazwy typow sa bardzo dlugie
#define VAR(v, n) __typeof(n) v = (n)
// ALL(c) reprezentuje pare iteratorow wskazujacych odpowiednio na pierwszy i za ostatni element w strukturach danych STL. Makro to jest bardzo przydatne chociazby w przypadku korzystania z funkcji sort, ktora jako parametry przyjmuje pare iteratorow reprezentujacych przedzial elementow do posortowania.
#define ALL(c) (c).begin(), (c).end()
// Ponizsze makro sluzy do wyznaczania rozmiaru struktur danych STL. Uzywa sie go w programach, zamiast pisac po prostu x.size() z uwagi na fakt, iz wyrazenie x.size() jest typu unsigned int i w przypadku porownywania z typem int, w procesie kompilacji generowane jest ostrzezenie.
#define SIZE(x) ((int)(x).size())
// Bardzo pozyteczne makro, sluzace do iterowania po wszystkich elementach w strukturach danych STL.
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
// Skrot - zamiast pisac push_back podczas wstawiania elementow na koniec struktury danych, takiej jak vector, wystarczy napisac PB
#define PB push_back
// Podobnie - zamiast first bedziemy pisali po prostu ST
#define ST first
// a zamiast second - ND.
#define ND second
// Funkcja wyznacza wartosc dwumianu Newtona
LL Binom(int n, int k) { 
#define Mark(x, y) for(int w = x, t = 2; w > 1; t++) \
while(!(w % t)) {w /= t; p[t] += y;}
	if (n < k || n < 0) return 0;
	int p[n + 1];
	REP(x, n + 1) p[x] = 0;
// Wyznacz wartosc liczby n!/(n-k)!=(n-k+1)*...*n w postaci rozkladu 
// na liczby pierwsze
	FOR(x, n - k + 1, n) Mark(x, 1);
// Podziel liczbe, ktorej rozklad znajduje sie w tablicy 
// p przez k!
	FOR(x, 1, k) Mark(x, -1);
// Wylicz wartosc wspolczynnika dwumianowego na podstawie 
// jej rozkladu na liczby pierwsze i zwroc wynik
	LL r = 1;
	FOR(x, 1, n) while(p[x]--) r *= x;
	return r;
}
int main() {
	int n, k;
// Dla wszystkich par liczb wyznacz wartosc dwumianu Newtona
	while(cin >> n >> k)
		cout << "Binom(" << n << "," << k << ") = " << Binom(n,k) << endl;
	return 0;
}
