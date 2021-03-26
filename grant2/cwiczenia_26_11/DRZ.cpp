#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &G, vector<bool> &visited, int start, vector<int> &dist) {
    visited[start] = true;
    dist[start] = 0;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for(int x : G[v]) 
            if(!visited[x]) {
                visited[x] = true;
                dist[x] = dist[v] + 1;
                Q.push(x);
            }
    }

}

int main() {
    int a,b;
    cin >> a >> b;
    vector<vector<int>> G(b+10);
    vector<bool> visited(b+10);
    vector<int> dist(b+10);
    int ln= 1,
        i = 1,
        l = 0,
        p = 0;
    while(p < b || l < b) {
        l = ln+1;
        p = ln+2;
        G[i].push_back(l);
        G[i].push_back(p);
        G[l].push_back(i);
        G[p].push_back(i);
        ln = p;
        i++;
    }
    bfs(G, visited, a, dist); 
    cout << dist[b] << '\n';
}

