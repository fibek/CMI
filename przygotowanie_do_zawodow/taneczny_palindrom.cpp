#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int a,b,n, price = 0;
	int k[1000];
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
		cin >> k[i];
	int f=0, l=n-1;
	bool p = true;
	while( f <= l && p ) {
		if( k[f] == 0 && k[l] == 0 ) {
			k[f] = k[l] = 1;
			l != f ? price += a+a : price += a;
			f++, l--;
		} else if( k[l] == 0 ) {
			k[l] = k[f];
			k[f] == 1 ? price += a : price += b;
			f++, l--;
		} else if( k[f] == 0 ) {
			k[f] = k[l];
			k[l] == 1 ? price += a : price += b;
			f++, l--;
		} else if( k[l] == k[f] )
			f++, l--;
		else
			p = false;
	} 
	if( f >= l )
		cout << price << '\n';
	else 
		cout << "-1\n";
}
