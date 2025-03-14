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
#include <list>
// Wartosc INF jest wykorzystywana jako reprezentacja nieskończonosci. Ma ona wartosc 1000000001, a nie 2147483647 (najwieksza wartosc typu int) ze wzgledu na dwa fakty - prosty zapis oraz brak przepelnienia wartosci zmiennej w przypadku dodawania dwoch nieskończonosci do siebie: ((int) 2147483647 + (int) 2147483647 = -2).
const int INF = 1000000001;
// Drzewo MaxTree umozliwia dodawanie elementow z przypisana im wartoscia oraz wyszukiwanie najwiekszej wartosci na dowolnym spojnym przedziale elementow
struct MaxTree {
    int* el, s;
// Konstruktor przyjmuje jako parametr wysokosc konstruowanego drzewa (dziedzina elementow to [0..2^size-1])
    MaxTree(int size) {
	el = new int[2*(s = 1<<size)];
	REP(x,2*s) el[x]=0;
    }
// Destruktor zwalnia zaalokowana pamiec
    ~MaxTree(){delete[] el;}
// Funkcja zmienia wartosc elementu p na v
    void Set(int p,int v) {
// Ustaw wartosc elementu p na v, oraz zaktualizuj wierzcholki na sciezce do korzenia, wyliczajac dla nich maksimum z ich lewego i prawego syna
	for(p+=s, el[p]=v, p>>=1; p>0; p>>=1)
	    el[p] = max(el[p<<1], el[(p<<1)+1]);
    }
// Funkcja wyznacza najwieksza wartosc na przedziale elementow [p..k]
    int Find(int p, int k) {
	int m = -INF;
	p+=s; k+=s;
// Przeszukiwanie drzewa rozpoczyna sie od lisci reprezentujacych elementy p i k. Dopoki wezel p jest rozny od wezla k...
	while(p<k) {
// Jesli przedzialy reprezentowane przez aktualne wezly p i k zawieraja sie calkowicie w  przeszukiwanym przedziale, to nastepuje aktualizacja wyniku
	    if((p&1)==1) m=max(m,el[p++]);
	    if((k&1)==0) m=max(m,el[k--]);
// Przejdz do ojcow wezlow p i k
	    p>>=1; k>>=1;
	}
	if(p==k) m=max(m,el[p]);
	return m;
    }
};
int main() { 
	int w1, w2, w3;
// Skonstruuj drzewo maksimow dla elementow [0..15]
	MaxTree tree(4);
// Wykonaj liste operacji...
	while(cin >> w1 >> w2 >> w3) {
		if (w1 == 0) {
// Operacja zmiany wartosci klucza...
			tree.Set(w2, w3);
			cout << "Zmiana wartosci elementu " << w2 << " na " << w3 << endl;
		} else
// Operacja wypisania maksimum na przedziale [w2..w3]
		cout << "Maksimum na przedziale " << w2 << ".." << w3 << 
			" = " << tree.Find(w2, w3) << endl;
	}
	return 0;
}
