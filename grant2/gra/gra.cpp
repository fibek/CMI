#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> P(n);
    for(int i = 0; i < n; i++) 
        cin >> P[i];
    for(int i = 0; i < n; i++) {
        if(P[i] > 0) 
            sum += P[i];
        else {
            int j = 0, maxv = P[i];
            cout << "\nminiv: " << maxv << "i: " << i << '\n';
            i++;
            while(i < n && P[i] < 0 && j < 6 ) {
                if(P[i] > maxv) 
                    maxv = P[i];
                j++; i++;
            }
            cout << "\nminiv: " << maxv << "i: " << i << '\n';
            sum += P[i];
        }
    }
    cout << '\n';
    cout << sum << '\n';
}

