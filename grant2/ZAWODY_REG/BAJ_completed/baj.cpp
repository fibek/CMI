#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,
	a,o,w;
    cin >> n;
    vector<int> A(n), O(n), W(n);

    for(int i = 1; i <= n; i++) {
	cin >> a >> o >> w;
	A[a-1] = O[o-1] = W[w-1] = i;
    }
    if(A[0] != O[0]) {
	if(O[0] != W[0])
	    cout << 3 << '\n';
	else
	    cout << 2 << '\n';
    } else {
	if(W[0] != O[0])
	    cout << 2 << '\n';
	else
	    cout << 1 << '\n';
    }
}

