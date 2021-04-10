#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    string s;
    cin >> n >> k >> s;
    int Z[26] = {0};
    for(int i = 0; i < s.size(); i++)
	Z[s[i]-'A']++;
    int mini = Z[0];
    for(int i = 1; i < k; i++)
	mini = min(Z[i], mini);
    cout << mini*k << '\n';
}

