#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void search(vector<vector<int>> G, vector<vector<ll>> W, vector<bool> visited, int start, int finish, ll minimal, vector<ll> &mins) {
    visited[start] = true;
    for(int x : G[start]) {
	if(x == finish) {
	    mins.push_back(min(minimal, W[start][x]) );
	    return;
	}
	if(!visited[x]) {
	    ll tmp = min(minimal, W[start][x]);
	    search(G, W, visited, x, finish, tmp, mins);
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K,Q;
    cin >> N >> K >> Q;
    N++;
    vector<vector<int>> G(N);
    vector<vector<ll>> W(N, vector<ll>(N));
    vector<bool> visited(N, false);
    for(int i = 0; i < K; i++) {
	int a,b,w;	
	cin >> a >> b >> w;
	G[a].push_back(b);
	G[b].push_back(a);
	W[a][b] = W[b][a] = w;
    }

    vector<vector<ll>> QUERIES(N, vector<ll>(N, LLONG_MAX));
    for(int i = 0; i < Q; i++) {
	int u,v;
	cin >> u >> v;
	ll mini = W[u][ G[u].front() ];
	vector<ll> minimals;
	search(G, W, visited, u, v, mini, minimals);
	for(int j = 1; j < minimals.size(); j++) 
	    mini = max(mini, minimals[j]);
	cout << mini << '\n';
    }
}

