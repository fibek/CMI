#include <bits/stdc++.h>

using namespace std;

int main() {
   int n,x,c=0,temp;
   vector<int> s;
   cin >> n;
   for(int i = 0; i < n; i++) {
       cin >> x;
       s.push_back(x);
   }
   for(int i = n-2; i >= 0; i--) {
       if(s[i] >= s[i+1]) {
           s[i] = s[i+1]-1;
           if(s[i] > 0)
               c++;
           else {
               cout << -1 << '\n';
               break;
           }
       }
   }

   cout << c << '\n';
}

