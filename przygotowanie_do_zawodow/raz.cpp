#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		int b = 0, e = s.size() - 1;
		while(b <= e) {
			if( s[b] != s[e] )
				cout << s[b] << s[e];
			else 
				cout << s[b];
			b++, e--;
		}
		cout << '\n';
	}	
}
