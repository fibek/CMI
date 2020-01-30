#include <iostream>

using namespace std;

bool is_palindrome(/*char *s*/string s);

int main() {
	int n,a,b;
	int price = 1;
	char k[1000];
	char cp[1000];
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) {
		cin >> k[i];	
		cp[i] = k[i];
	}

	for(int i = 0; i < n; i++) {
		if(k[i] == '0') {
			cp[i] = '1';
			price += a;
		}
	}
	int i = 0;
	while( !is_palindrome(cp) && i < n ) {
		if(k[i] == '0' && cp[i] == '1') {
			cp[i] = '2';
			price = price - a + b;
		}
		i++;
	}

	i = 0;
	while( !is_palindrome(cp) && i < n ) {
		if(k[i] == '0' && cp[i] == '2') {
			cp[i] = '1';
			price = price - b + a;
		}
		i++;
	}

	if( i >= n && !is_palindrome(cp) )
		cout << price << '\n';
	else 
		cout << "NIE\n";
}

bool is_palindrome(/*char *s*/string s) {
	int b = 0;
	int e = s.size() - 1;
	bool p = false;
	while( s[b] == s[e] && b != e ) {
		b++; e--;
		p = true;
	}
	return p;
}
