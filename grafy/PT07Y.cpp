#include <iostream>
#include <vector>

using namespace std;

bool visit[100000000] = {false};
vector<int> G[20000];
void dfs(int node) {
	visit[node] = true;
	for(int i = 0; i < G[node].size(); i++)
		if(!visit[G[node][i]])
			dfs(G[node][i]);
}
	
int main() {
	int n,m,u,v;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		if(u != v) {
			G[u].push_back(v);
			G[v].push_back(u);
		} else
			G[u].push_back(v);
	}	
	if(m == n - 1) {
		int c=0;
		for(int i = 1; i <= n; i++) {
			dfs(i);
			if(!visit[n])
				c++;
		}
		if(c == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	} else
		cout << "NO\n";
}
