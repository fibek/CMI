#include <bits/stdc++.h>

using namespace std;

string toBin(int a) {
    string out="";
    while(a > 0) {
        out = (a%2==1) ? "1"+out : "0"+out;
        a /= 2;
    }
    return out;
}

int main() {
    //bin2dec
    bitset<32> a;
    cin >> a;
    cout << a.to_ulong() << '\n';
    //dec2bin
    int b;
    cin >> b;
    cout << toBin(b) << '\n';
}
