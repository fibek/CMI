#include <bits/stdc++.h>

using namespace std;

const int M{ 1000000007 };
const int P[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; //tablica liczb pierwszych do 100
const int NP = sizeof(P)/sizeof(int);  //wyliczona ilosc liczb pierwszych == rozmiar tablicy P
typedef long long ll; //alias na nazwe typu long long 

//faktoryzacja == rozklad liczb na czynniki pierwsze
void factorize(int k, int powers[], int sign) {// sign == czy funkcja ma budowac licznik czy mianonwik (dodawac czy odejmowac)
    int i{ }; // int i = 0;
    while(k > 1) { //k bedzie dzielone przez czynniki, wiec na koniec bedzie 1
	if(k % P[i] == 0) {
	    powers[i] += sign;
	    k /= P[i];
	} else 
	    i++;
    }
}

//factorial == silnia
//faktoryzacja calego n!
void split_factorial(int n, int powers[], int sign) {
    for(int k{ 2 }; k <= n; k++) 
	factorize(k, powers, sign);
}

//jak podniesc cos wygodnie szybko do duzej potegi modulo M  (potegowanie modularne)
ll modular_power(int a, int m) {
    if(m == 0) 
	return 1;
    ll x = modular_power(a, m/2);
    x = (x * x) % M;
    if(m % 2 > 0) 
	x = (x * a) % M;
    return x;
}

//zliczanie ile razy wystepuje kazda litera
int name_count(string name) {
   int letters[26] = {};  //wyzerowanie licznikow, moze byc " = {0}; ", ale " = {1} " nie da wszedzie jedynek !!
   for(char c : name) // petla for each
	letters[c-'a']++; //c (w kontekscie arytemetycznym) to kod ascii
   int powers[NP] = { };  // uzywanie NP, poniewaz jakbym chcial zmienic tablice liczb pierwszych to tu nie musze zmieniac
   // numerator == licznik
   split_factorial(name.size(), powers, 1);
   // denominator == mianowik
   for(int q : letters)
       if(q > 1)
	   split_factorial(q, powers, -1); 
   ll result{ 1 };
   for(int i=0; i < NP; i++)
       result = (result * modular_power(P[i], powers[i])) % M; // funkcja powers musi zwracac modulo ( potegowanie modularne )
   return result;
}

int main() {
    string name;
    cin >> name;
    cout << name_count(name) << '\n';
}

