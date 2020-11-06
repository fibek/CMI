#include <iostream>
#include <vector>

using namespace std;

vector<int> G[200000];
bool visit[200000] = {false};
int T[20000] = {0};
void dfs(int node) {
	visit[node] = true;
	int i = 0;
	bool free = true;
	while(i < G[node].size() && free) {
		if(!visit[G[node][i]]) {
			T[G[node][i]] = node;
			free = false;
			dfs(G[node][i]);
		}
		i++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n,m,a,b;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if( m >= n ) {
		for(int i = 1; i <= n; i++) {
			dfs(i);
			for(int j = 0; j <= n; j++)
				visit[j] = false;
		}
		cout << "TAK\n";
		for(int i = 1; i <=n; i++)
			cout << T[i] << '\n';
	} else 
		cout << "NIE\n";
}	
