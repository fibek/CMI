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
    int W[100000] = {0};
    cin >> s >> T;
    for(int k = 1; k <= s.size()/2; k++) 
	for(int i = 0; i < s.size()-k; i++)
	    twoword(i,k,W[k]);
    int k;
    for(int t = 0; t < T; t++) {
	cin >> k;
	cout << W[k] << '\n';
    }
}

