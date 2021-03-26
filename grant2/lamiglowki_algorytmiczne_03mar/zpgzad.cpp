#include <bits/stdc++.h>

using namespace std;

int nwd(int a, int b) {
    if(b == 0)
	return a;
    return nwd(b, a%b);
}

int mini;
bool compare_nwd(int a, int b) {
    if(nwd(a,b) == mini)
	return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    cin >> L[0];
    mini = L[0];
    for(int i = 1; i < n; i++) {
	cin >> L[i];
	mini = min(mini, L[i]);
    }

    for(int i = 0; i < n; i++)
	cout << L[i] << ' ';
    cout << '\n';
}

