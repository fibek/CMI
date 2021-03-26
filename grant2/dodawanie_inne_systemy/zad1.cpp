#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b,sum = "";
    int base;
    cin >> a >> b >> base;
    while(a.size() < b.size()) 
	a = '0'+a;
    while(b.size() < a.size()) 
	b = '0'+b;
    int s,p, aa,bb;
    char ch;
    p = 0;
    for(int i = b.size()-1; i >= 0; i--) {
	aa = (a[i] <= '9') ? a[i]-'0' : a[i]-'A'+10;
	bb = (b[i] <= '9') ? b[i]-'0' : b[i]-'A'+10;
	s = p + aa + bb;
	ch = (s%base <= 9) ? (s%base)+'0' : (s%base)+'A'-10;
	sum = ch + sum;
	p = s/base;
    }
    if( p == 0 )
	cout << sum << '\n';
    else
	cout << 1 << sum << '\n';
}

