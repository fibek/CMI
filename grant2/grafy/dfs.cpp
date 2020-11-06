#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> G, vector<bool> &visited, int s) {
    visited[s] = true;
    for(int x : G[s]) 
        if(!visited[x])
            dfs(G, visited, x);
}

int main() {
    vector<vector<int>> G;
    vector<bool> visited;
    int V,E,a,b;
    cin >> V >> E;
    G.resize(V+1);
    visited.resize(V+1);
    for(int i = 0; i < E; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    } 
    dfs(G, visited, 1);
}

