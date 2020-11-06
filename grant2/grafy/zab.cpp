#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> G, vector<bool> &visited, int s) {
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for(int x : G[v])
            if(!visited[x]) {
                visited[x]=true;
                Q.push(x);
            }
    }
}


int main() {
    int N,a,b,k=0;
    cin >> N;
    vector<vector<int>> G;
    vector<bool> visited;
    visited.resize(N+1);
    G.resize(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> a >> b; 
        if(a != b) {
            G[i].push_back(a);
            G[i].push_back(b);
        } else
            G[i].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            bfs(G, visited, i); 
            k++;
        }
    }
    cout << k << '\n';
}

