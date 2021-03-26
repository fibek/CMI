#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> V(n);
    for(int i = 0; i < n; i++) 
	cin >> V[i];
    sort(V.begin(), V.end());
    int sum=V[0];
    int i = 1;
    while(sum < b) {
	sum += V[i];
	i++;
    }
    cout << i-1 << '\n';	
}

