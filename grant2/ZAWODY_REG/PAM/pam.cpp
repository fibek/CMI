#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> G, vector<bool> &visited, int s, 
	 vector<int> S_type, vector<int> &SOUV, bool &FL) {
    visited[s] = true;
    SOUV[ S_type[s] ]++;
    for(int x : G[s]) {
	if(x == 1) {
	    FL = true;
	    return;
	}
	if(!visited[x])
	    dfs(G,visited, x, S_type, SOUV, FL);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p,u;
    cin >> p >> u;
    vector<vector<int>> G(p+1);
    vector<int> S_type(p+1);
    for(int i = 0; i < p; i++)
	cin >> S_type[i+1];
    for(int i = 0; i < u; i++) {
	int a,b;
	cin >> a >> b;
	G[a].push_back(b);
    }

    vector<bool> visited(p+1,false);
    vector<int> SOUVENIRS(p+1, 0);
    bool flag;
    dfs(G,visited,1, S_type, SOUVENIRS, flag);
    if(flag)
	cout << "NIE\n";
    else {
	int maxs = 0;
    	for(auto x : SOUVENIRS)
    	    maxs = max(maxs, x);
    	cout << maxs << '\n';
    }
}
