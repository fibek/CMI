#include <bits/stdc++.h>

using namespace std;

int minimum(int a, int b, int c) {
    if(a < b) {
	if(a < c)
	    return a;
	return c;
    }
    if(c < b)
	return c;
    return b;
}

int distance(string a, string b) {
    vector<vector<int>> V;
    int n = a.size()+1,
	m = b.size()+1;
    V.resize(n);
    for(int i = 0; i < n; i++) {
	V[i].resize(m,0);
	V[i][0] = i;
    }
    for(int j = 0; j < m; j++) 
	    V[0][j]=j;

    int cost;
    for(int i = 1; i < n; i++) {
	for(int j = 1; j < m; j++) {
	    cost = (a[i-1] == b[j-1]) ? 0 : 1;
	    V[i][j] = minimum(V[i][j-1]+1, V[i-1][j-1]+cost, V[i-1][j]+1);
	}
    }

    return V[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string,string> U;
    map<int, vector<pair<string,string>>> M;
    for(int i = 0; i < n; i++) {
	string nick,pass;
	cin >> nick >> pass;
	U[nick] = pass;
    }
    int mind = 205, maxd = 0;
    for(auto it = U.begin(); it != U.end(); it++) {
	auto it2 = it;
	it2++;
	while(it2 != U.end()) {
	    int dis = distance(it->second, it2->second);
	    mind = min(dis, mind);
	    maxd = max(dis, maxd);
	    M[dis].push_back(make_pair(it->first, it2->first));
	    it2++;
	}
    }
    cout << mind << '\n';
    for(auto x : M[mind])
	cout << x.first << ' ' << x.second << '\n';
    cout << maxd << '\n';
    for(auto x : M[maxd])
	cout << x.first << ' ' << x.second << '\n';
}

