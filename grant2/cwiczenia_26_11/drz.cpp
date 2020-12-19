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
    int a,b, gr;
    cin >> a >> b;
    gr = (a > b) ? a : b;
    vector<vector<int>> G(gr+10);
    vector<bool> visited(gr+10);
    vector<int> dist(gr+10);
    int ln= 1,
        i = 1,
        l = 0,
        p = 0;
    while(p < gr || l < gr) {
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

