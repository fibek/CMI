#include <bits/stdc++.h>

using namespace std;

int nwd(int a, int b) {
    if(b == 0)
        return a;
    return nwd(b, a%b);
}

int main() {
   int n;
   string s;
   cin >> n;
   for(int i = 0; i < n; i++) {
       cin >> s;
       bitset<15> per(s);
       int p = per.to_ullong();
       string s2;
       s2.assign(s.size(), '1');
       bitset<15> den(s2);
       int q = den.to_ullong();
       int n = nwd(p,q);
       cout << p/n << '/' << q/n << '\n';
   }
}

