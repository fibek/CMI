#include <bits/stdc++.h>

using namespace std;

int c = 0;

int bfs(vector<vector<int>> G, vector<bool> &visited, int s) {
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for( int x : G[v] )  {
            if(!visited[x]) {
                visited[x] = true;
                Q.push(x);
                c++;
            }
        }
    }
    return c;
}

int main() {
   int n,m,a,b;
   cin >> n >> m;
   vector<vector<int>> G;
   G.resize(n+1);
   for(int i = 0; i < m; i++) {
       cin >> a >> b;
       G[a].push_back(b);
       G[b].push_back(a);
   }

   vector<bool> visited;
   visited.resize(n+1);
   int maxi = bfs(G, visited, 1);
   int k;
   for(int i = 2; i <= n; i++) {
        c=0;
        if(!visited[i]) {
            k = bfs(G, visited, i);
            maxi = max(maxi, k);
        }
   }
   cout << maxi << '\n';
}

