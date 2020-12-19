#include <bits/stdc++.h>

using namespace std;

int main() {
   int n,m,a,b;
   cin >> n >> m;
   vector<pair<int,int>> D;
   vector<int> G(m);
   vector<bool> PD(n, false);
   for(int i = 0; i < n; i++) {
       cin >> a >> b;
       D.push_back( make_pair(a,b) );
   }
   for(int i = 0; i < m; i++) 
       cin >> G[i];
   
   bool all = false;
   int j = 0, c = 0;
   while(!all && j < m) {
       for(int i = 0; i < n; i++)  
           if(!PD[i] && G[j] >= D[i].first && G[j] <= D[i].second)  {
               PD[i] = true;
               c++;
           }
       j++;
       if(c == n) {
           cout << j << '\n';
           all = true;
       }
   }
}

