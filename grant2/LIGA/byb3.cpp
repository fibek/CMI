#include <bits/stdc++.h>

using namespace std;

string s;

void twoword(int index, int length, int &count) {
    int i = index, j = i+length;
    for(int l = 0; l < length; l++) {
	if(s[i] != s[j]) 
	    return;
	i++; j++;
    }
    count++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> s >> T;
    vector<int> W(s.size(), -1);
    int k;
    for(int t = 0; t < T; t++) {
	cin >> k;
	if(k <= s.size()/2) { 
	    if(W[k] == -1) {
		int c = 0;
		for(int i = 0; i < s.size()-k; i++)
		    twoword(i,k,c);
		W[k] = c;
	    }
	    cout << W[k] << '\n'; 
	} else 
	    cout << 0 << '\n';
    }
}

