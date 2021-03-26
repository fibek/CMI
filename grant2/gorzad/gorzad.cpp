#include <bits/stdc++.h>

using namespace std;

int main() {
    int z,s,a,b,c;
    cin >> z;
    for(int i = 0; i < z; i++) {
	cin >> s >> a >> b >> c;
	ile_moze = s/c;
	cos = ile_moze / a;
	reszta = ile_moze % a;
	p = cos*a;
	p += cos*b;
	p += reszta/c;
	cout << p << '\n';
}

