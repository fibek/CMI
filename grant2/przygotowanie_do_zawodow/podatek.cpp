#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
   cin >> n;
   string s;
   string out;
   for(int i = 0; i < n; i++) {
       out = "";
       cin >> s;
       sort(s.begin(), s.end(), std::greater<char>());
       int j =0;
       while(s[j] == '1' && s[j+1] == '1')  {
           out = '1' + out;
           j+=2;
       }
       for(; j < s.size(); j++) 
           out = s[j] + out;
       cout << out  << '\n';
   }
}

