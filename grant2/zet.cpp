#include <bits/stdc++.h>

using namespace std;

int main() {
   int n,m,a,b;
   string s;
   cin >> n >> m;
   cin >> s;
   for(int i = 0; i < m; i++) {
       cin >> a >> b;
       for(int j = a-1; j < b; j++) 
           s[j] = (s[j] == 'A') ? 'R' : 'A' ;
   }
   cout << s << '\n';
}

