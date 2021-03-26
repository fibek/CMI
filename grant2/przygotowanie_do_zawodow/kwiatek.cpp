#include <bits/stdc++.h>

using namespace std;

int main() {
   int n, d, c=0;
   string s;
   cin >> n >> d;
   cin >> s;
   int i = 0;
   while(i < n-1 && i > 0){
       i+=d;
       while(s[i] != '1' && i > 0)  
            i--;
       c++;
   }
   if( i == 0 ) {
          cout << -1 << '\n';
   } else 
   cout << c << '\n';
}

