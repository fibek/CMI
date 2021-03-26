#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
   string s;
   cin >> n;
   for(int i =0; i < n; i++)  {
       cin >> s;
       for(int j=0; j < s.size(); j++) {
           bitset<8> bin(s[j]);
           if(bin.count() % 2 != 0) {
               //zamiana piatego bitu na 0 lub 1
               bin.set(5, ~bin[5]);
               cout << char(bin.to_ulong());
           } else
               cout << s[j] ;
       }
       cout << '\n';
   }
        
}

