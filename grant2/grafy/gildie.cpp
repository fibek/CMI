#include <bits/stdc++.h>

using namespace std;

int main() {
   int n, m, a, b;
   vector<vector<int>> G;
   vector<bool> visited;
   cin >> n >> m;
   for(int i = 0; i < m; i++) {
       cin >> a >> b;
       G[a].push_back(b);
       G[b].push_back(a);
   }

}

