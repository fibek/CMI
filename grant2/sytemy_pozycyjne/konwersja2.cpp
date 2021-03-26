#include <bits/stdc++.h>

using namespace std;

int main() {
    //bin2dec
    bitset<32> a; //rozmiar int'a wynosi 4 bajty = 32 bity
    cin >> a;
    cout << a.to_ulong() << '\n';
    
    //dec2bin
    int b;
    cin >> b;
    bitset<32> c(b);
    string s = c.to_string();
    s.erase(0, s.find_first_not_of("0")); //wycinanie wiodacych zer
    cout << s << '\n';
}
