#include <bits/stdc++.h>

using namespace std;

unsigned int dijkstra(vector<vector<int>> G, vector<vector<unsigned int>> W, vector<unsigned int> P, vector<bool> visited, int w1, int w2, int n) {
    queue<int> Q;
    Q.push(w1);
    P[w1] = 0;
    while(!Q.empty()) {
	int v = Q.front();
	Q.pop();
	for(int x : G[v]) {
	    P[x] = min(P[v]+W[x][v], P[x]);
	    if(!visited[x])
		Q.push(x);
	}
	visited[v] = true;
    }
    return P[w2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, w1,w2,k;
    cin >> n >> m;
    vector<vector<int>> G;
    vector<unsigned int> ww(m+1);
    vector<vector<unsigned int>> W;
    vector<bool> visited;
    vector<unsigned int> P;
    W.resize(m+1, ww);
    G.resize(n+1);
    visited.resize(n+1);
    P.resize(n+1, UINT_MAX);
    for(int i = 0; i < m; i++) {
	cin >> w1 >> w2 >> k;
	G[w1].push_back(w2);
	G[w2].push_back(w1);
	W[w1][w2] = k;
	W[w2][w1] = k;
    }
    int p;
    cin >> p;
    for(int i = 0; i < p; i++) {
	cin >> w1 >> w2;
	cout << dijkstra(G, W, P, visited, w1, w2, n) << '\n';
    }
}

