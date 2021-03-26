#include <bits/stdc++.h>

using namespace std;

void ulamek(int p, int q) {
    if(p != 1) {
	int x = p/q;
	cout << x << ' ';
	ulamek(q, p-(q*x));
    }
}

int main() {
    int p,q;
    cin >> p >> q;
    if(p>q)
	ulamek(p, q);
    else
	ulamek(q, p);
    cout << '\n';
}

