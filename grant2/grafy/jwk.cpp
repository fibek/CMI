#include <bits/stdc++.h>

using namespace std;

bool found = false;

void bfs(vector<vector<int>> G, vector<bool> &visited, int s) {
    visited[s] = true; 
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int v = Q.front(); 
        Q.pop();
        for(int x : G[v]) {
            if(v != s) {
                for(int y : G[x]) {
                    if( x != s && y == s ) {
                        found = true;
                        return;
                    }
                }
            }
            if(!visited[x]) {
                Q.push(x);
                visited[x] = true;
            }
        }
    }
}


int main() {
    int n,m,a,b;
    vector<vector<int>> G;
    cin >> n >> m;
    G.resize(n+1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }   
    vector<bool> visited(n+1);
    int v=1;
    bfs(G, visited, v);
    if(found) 
        cout << "TAK\n";
    else
        cout << "NIE\n";
}

