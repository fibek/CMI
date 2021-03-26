#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n;
    string s;
    map<char, int> M;
    cin >> T;
    for(int t = 0; t < T; t++) {
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < 6; j++) {
		char ch;
		cin >> ch;
		if(s.find(ch) != string::npos) 
		    M[ch] = M[ch]+1;
	    }
	}
	int cl = 0;
	for(int i = 0; i < s.size(); i++)  {
	    cout << M[ s[i] ] << ' ';
	    if( M[ s[i] ] < 1 ) 
		cl++;
	}
	if(cl > 0) //zmien na krotsza wersje if
	    cout << cl << '\n';
	else
	    cout << "TAK\n";
    }
    
}

