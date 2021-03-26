#include <bits/stdc++.h>

using std::cin;
using std::cout; 
using std::vector; 
using std::queue;

unsigned int dijkstra(vector<vector<int>> G, vector<vector<int>> W, int n, int m, int w1, int w2) {
    queue<int> Q;
    vector<unsigned int> P;
    P.resize(n+1, UINT_MAX);
    Q.push(w1);
    P[w1] = 0;
    vector<bool> visited;
    visited.resize( G.size() );
    while(!Q.empty()) {
	int v = Q.front();
	visited[v] = true;
	Q.pop();
	int minv = 0;
	for(int x : G[v]) {
	    if(!visited[x])  {
		P[x] = std::min(P[v]+W[v][x], P[x]);
		minv = (P[x] < P[minv]) ? x : minv;
	    }
	}
	if(minv > 0)
	    Q.push(minv);
    }
    return P[w2];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<vector<int>> G;
    vector<vector<int>> W;
    cin >> n >> m;
    G.resize(n+1);
    vector<int> WW(m+1);
    W.resize(m+1, WW);
    for(int i = 0; i < m; i++) {
	int w1,w2,k;
	cin >> w1 >> w2 >> k;
	G[w1].push_back(w2);
	G[w2].push_back(w1);
	W[w1][w2] = k;
	W[w2][w1] = k;
    }
    int p;
    cin >> p;
    for(int i = 0; i < p; i++) {
	int w1,w2;
	cin >> w1 >> w2;
	cout << dijkstra(G, W, n, m, w1, w2) << '\n';
    }
}

