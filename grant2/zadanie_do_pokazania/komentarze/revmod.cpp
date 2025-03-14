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
#define TPL template<class T> inline
#define CR(t) const t&
#define RET return
TPL T gcd(CR(T)a,CR(T)b) { RET b?gcd(b,a%b):a; }
// Funkcja wyznacza najwiekszy wspolny dzielnik dwoch liczb oraz wspolczynniki l i k
int GCDW(int a, int b, LL &l, LL &k) {
    if (!a) { 
// gcd(0, b) = 0 * 0 + 1 * b
		l=0; k=1; return b; }
// Wyznacz rekurencyjnie wartosc najwiekszego wspolnego dzielnika oraz wspolczynniki l oraz k
    int d = GCDW(b%a, a, k, l);
// Zaktualizuj wartosci wspolczynnikow oraz zwroc wynik
    l -= (b/a)*k;
    return d;
}
// Funkcja wyznacza odwrotnosc modularna liczby a (mod m)
int RevMod(int a, int m){ 
	LL x, y;
	if (GCDW(a, m, x, y) != 1) return -1;
// Dokonaj przesuniecia zmiennej x, tak aby znajdowala sie w przedziale [0..m-1]
	x %= m;
	if (x < 0) x += m;
	return x;
}
int main() {
	int a, m;
// Dla wszystkich par liczb wyznacz rozwiazanie rownania modularnego
	while(cin >> a >> m) {
		cout << "Rownanie: " << a << "*x = 1 (mod " << m << ")" << endl;
		int sol = RevMod(a,m);
		if (sol == -1) 
			cout << "Brak rozwiazan" << endl;
		else
			cout << "x = " << sol << endl;
	}
	return 0;
}
