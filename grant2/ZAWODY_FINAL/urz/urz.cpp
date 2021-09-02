#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.first <= b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin >> t >> n;
    vector<pair<int,int>> count_t(t+1, make_pair(0,0));
    for(int i = 0; i < n; i++) {
	int x;
	cin >> x;
	count_t[x] = make_pair(count_t[x].first+1, x);
    }
    sort(count_t.begin(), count_t.end(), comp);
    auto it1 = count_t.rbegin(), it2 = ++it1;
    int s1 = it1->second, s2 = it2->second;
    Z
    /* if( (s1 == 1 && s2 == 2) || (s2 == 2 && s1 == 1) ) { */
	/* cout << (it->first+it */
}
