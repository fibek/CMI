#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> G, vector<bool> visited, int start, int length, int &max_length) {
    int v = start;
    max_length = max(max_length, length);
    visited[v] = true;
    for(int x : G[v]) 
	if(!visited[x]) 
	    dfs(G, visited, x, length+1, max_length);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
	vector<vector<int>> G;
	vector<bool> visited;
	int n;
	cin >> n;
	G.resize(n+1);
	visited.resize(n+1);
	for(int i = 1; i < n; i++) {
	    int a,b;
	    cin >> a >> b;
	    G[a].push_back(b);
	    G[b].push_back(a);
	}
	int max_l = 0;
	for(int i = 0; i < n; i++)
	    dfs(G, visited, i, 0, max_l);
	cout << max_l*100 << '\n';
    }
}

