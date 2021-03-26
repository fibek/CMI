#include <bits/stdc++.h>

using namespace std;

vector<int> T;
int base = 2;

void add(int qty, int price) {
    price += base;
    T[price] += qty;
    price /= 2;
    while(price > 0) {
	T[price] = T[2*price] + T[2*price+1];
	price /= 2;
    }
}

bool remove(int qty, int price) {
    price += base;
    if(T[price]-qty < 0)
	return false;
    T[price] -= qty;
    price /= 2;
    while(price > 0) {
	T[price] -= qty;
	price /= 2;
    }
    return true;
}

int query(int a, int b) {
    a+=base-1;
    b+=base+1;
    int result = 0;
    while(a/2 != b/2) {
	if(a%2 == 0) result += T[a+1];
	if(b%2 == 1) result += T[b-1];
	a /= 2;
	b /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while(base <= n)
	base*=2;
    T.resize(2*base, 0);
    for(int i = 0; i < n; i++) {
	int x,a,b;
	cin >> x >> a >> b;
	switch(x) {
	    case 0:
		cout << query(a,b) << '\n';
		break;
	    case 1:
		add(a,b);
		break;
	    case 2:
		cout << (remove(a,b) ? "OK\n" : "NIE\n" );
		break;
	}
    }
}

