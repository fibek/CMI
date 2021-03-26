#include <bits/stdc++.h>

using namespace std;

void count_kokoko(vector<vector<bool>> G, int V, int s, int start, int &kokoko, vector<int> &v, int parent) {
    for(int i = 1; i <= V; i++) 
    	if(G[s][i] && !G[start][i] && !G[parent][i]) {
    	    v.push_back(i);
    	    kokoko++;
    	}
}

void dfs(vector<vector<bool>> G, int V, int s, int t, int start, int &kokoko, vector<int> &v, int parent) {
    for(int i = 1; i <= V; i++) 
	if(G[s][i]) {
	    if(t <= 1) 
		dfs(G, V, i, t+1, start, kokoko, v, s);
	    else {
		if(G[start][i])
		    continue; 
		if(t == 3) {
		    count_kokoko(G, V, s, start, kokoko, v, parent);
		    break;
		}
		dfs(G, V, i, t+1, start, kokoko, v, s);
	    }
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<bool>> G;
    G.resize(n+1);
    char ch;
    for(int i = 1; i <=  n; i++) {
	G[i].resize(n+1);
	for(int j = 1; j <= n; j++) {
	    cin >> ch;
	    if(ch == 'T') 
		G[i][j] = true;
	}
    }
    int kokoko;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
	kokoko =  0;
	v.resize(0);
	dfs(G, n, i, 1, i, kokoko, v, 0);
	cout << kokoko << '\n';
	for(int i = 0; i < v.size(); i++)
	    cout << v[i] << ' ';
	cout << '\n';
    }
}

