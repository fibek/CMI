#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    if((N*M)%2 == 1)
	cout << 0 << '\n';
    else {
	int count = 0;
	count += N+2;
	if(M % 2 == 1)
	    count += ((M/2)+1+M) % MOD;
	else
	    count += ((M/2)+M) % MOD;
	cout << count%MOD << '\n';
    }
}

