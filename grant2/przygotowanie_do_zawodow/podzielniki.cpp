#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x;
    multiset<int> P;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        P.insert(x);
    }
    P.erase(1);
    //odwrotny iterator, bo P.end() wskazuje na element poza zbiorem
    multiset<int>::reverse_iterator it = P.rbegin(); //ostatni element zbioru
    int num = *it; 
    for(int i = 2; i <= num/2; i++) 
        if(num % i == 0)
            P.erase(P.find(i));
    it++; //ustawiamy iterator na drugi najwiekszy element zbioru
    cout << num << ' ' << *it << '\n';
}

