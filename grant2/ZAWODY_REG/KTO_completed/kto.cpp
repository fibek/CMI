#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> SUSPECTS_W;
int m;

bool check(pair<int, int> P) {
    int count = 0;
    for(auto x : SUSPECTS_W) {
	if(P.first == x.first || P.first == x.second ||
	   P.second == x.first || P.second == x.second) 
		count++; 
    }
    return (count >= m);	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> m;
    vector<int> V(n+1,0);
    for(int i = 0; i < n; i++) {
	int a,b;
	cin >> a >> b;
	V[a]++;
	V[b]++;
	SUSPECTS_W.push_back(make_pair(a,b));
    }

    int count = 0;
    vector<pair<int,int>> SUSPECT_C;
    for(int i = 1; i <= n; i++) 
	for(int j = i+1; j <= n; j++) 
	    if(i != j && V[i]+V[j] >= m) 
		SUSPECT_C.push_back(make_pair(i,j));

    auto it = SUSPECT_C.begin();
    for(; it != SUSPECT_C.end(); )
	if(!check(*it))
	    it = SUSPECT_C.erase(it); 
	else
	    ++it;

    cout << SUSPECT_C.size() << '\n';

}

