#include <bits/stdc++.h>

using namespace std;

int count_ways(int x, int e) {
    /* cout << "x: " << x << endl; */
    if(x+2 <= e)
        return count_ways(x+2, e) + count_ways(x+1, e);
    if(x+2 > e && x+1 <= e) 
        return count_ways(x+1, e);
    if(x == e) 
        return 1;
}

int pot(int a) { 
    bitset<32> b;
    b.set(a, 1);
    int y = b.to_ullong();
    return y;
}

int main() {
   int z,s,p,c,n;
   cin >> z;
   for(int i = 0; i < z; i++) {
       cin >> s >> p;
       c = count_ways(0, s);
       n = pot(p);
       cout << c%n << '\n';
   }
}

