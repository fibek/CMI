#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    string s;
    vector<int> ile;
    cin >> n >> k;
    cin >> s;
    ile.resize(k, 0);
    for(int i = 0; i < n; i++) 
        ile[s[i]-'A']++;
    int mini = ile[0];
    for(int i = 1; i < k; i++) 
       mini = min(mini, ile[i]); 
    cout << mini * k << '\n';
}

