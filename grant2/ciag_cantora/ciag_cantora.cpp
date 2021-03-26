#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, q;
    p = q = 1;
    cin >> n;
    while(n != 1) {
	p++;
	q--;
	n--;
	if(q == 0) {
	    q = p;
	    p = 1;
	}
    }
    cout << p << '/' << q << '\n';
}

