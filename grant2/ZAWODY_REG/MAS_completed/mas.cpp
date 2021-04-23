#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll modular_power(int x, int e) {
    if(e == 0)
	return 1;
    ll p = modular_power(x, e/2);
    p = (p*p) % n;
    if(e % 2 > 0)
	p = (p*x) % n;
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,x,count;
    ll result = 0;
    cin >> N >> x >> n;
    for(int i = 2; i <= N; i++) {
	cin >> count;
	ll p = count*modular_power(x, i);
	result = (result+p)%n;
    }
    cout << result << '\n';
}

