#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {
    vector<vector<int>> V(s1.size()+1, vector<int>(s2.size()+1), 0);
    for(int i = 1; i <= s1.size(); i++)
	for(int j = 1; j <= s2.size(); j++)
	    if(s1[i-1] == s2[j-1])
		V[i][j] = V[i-1][j-1]+1;
	    else
		V[i][j] = max(V[i-1][j], V[i][j-1]);
    return V[s1.size()][s2.size()];
}

int main() {
    string s1,s2;
}

